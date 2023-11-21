/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:44:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/21 18:46:44 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

typedef struct s_params
{
	int	sig_send;
	int	valid;
}		t_params;

void	confirmation(int sig, siginfo_t *info, void *context)
{
	t_params	*params;

	params = (t_params *)context;
	ft_printf("params.valid = %d et params.sig_send = %d, tandis que sig = %d\n", params->valid, params->sig_send, sig);
	(void)info;
	if (sig == params->sig_send)
		params->valid = 1;
	else
		params->valid = 0;
	ft_printf("params.valid apres test:%d\n", params->valid);
}

void	send_to(char c, pid_t serv_pid)
{
	int					i;
	int					bit;
	struct sigaction	sa;
	t_params			params;

	i = 7;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = confirmation;
	params.valid = 1;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			params.sig_send = SIGUSR1;
			kill(serv_pid, SIGUSR1);
			ft_printf("bit = 1\n");
			sigaction(SIGUSR1, &sa, NULL);
			while (params.valid == 0)
				;
		}
		else
		{
			params.sig_send = SIGUSR2;
			ft_printf("sig_send avant sigaction = %d\n", params.sig_send);
			kill(serv_pid, SIGUSR2);
			ft_printf("bit = 0\n");
			sigaction(SIGUSR2, &sa, NULL);
			while (params.valid == 0)
				;
		}
		i--;
		usleep(650);
	}
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	serv_pid;
	char	*str;
	int		i;

	if (argc != 3)
		ft_error("Error args");
	serv_pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while(str[i])
	{
		send_to(str[i], serv_pid);
		i++;
	}
	return (0);
}
