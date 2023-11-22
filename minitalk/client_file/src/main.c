/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:44:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/22 15:38:52 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_valid;

typedef struct s_var
{
	int	i;
	int	bit;
	int	repeat;
}		t_var;

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	is_2(int sig)
{
	if (sig == SIGUSR2)
		g_valid = 1;
	else
		g_valid = 0;
}

void	is_1(int sig)
{
	if (sig == SIGUSR1)
		g_valid = 1;
	else
		g_valid = 0;
}

void	send_to(char c, pid_t serv_pid)
{
	t_var	var;

	var.i = 8;
	signal(SIGUSR2, is_2);
	signal(SIGUSR1, is_1);
	while (var.i-- > 0)
	{
		g_valid = 0;
		var.bit = (c >> var.i) & 1;
		var.repeat = 0;
		while (var.repeat < 10)
		{
			if (var.bit == 1)
				kill(serv_pid, SIGUSR1);
			else
				kill(serv_pid, SIGUSR2);
			pause();
			if (g_valid)
				break ;
			else
				var.repeat++;
		}
		if (var.repeat >= 10)
			ft_error("Échec de la transmission\n");
	}
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
	while (str[i])
	{
		usleep(500);
		send_to(str[i], serv_pid);
		i++;
	}
	return (0);
}
