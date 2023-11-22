/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:44:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/22 14:06:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	valid;

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	is_2(int sig)
{
	if (sig == SIGUSR2)
		valid = 1;
	else
		valid = 0;
}

void	is_1(int sig)
{
	if (sig == SIGUSR1)
		valid = 1;
	else
		valid = 0;
}

void	send_to(char c, pid_t serv_pid)
{
	int	i;
	int	bit;
	int	repeat;

	i = 7;
	signal(SIGUSR2, is_2);
	signal(SIGUSR1, is_1);
	while (i >= 0)
	{
		valid = 0;
		bit = (c >> i) & 1;
		repeat = 0;
		while (repeat < 10)
		{
			if (bit == 1)
			{
				kill(serv_pid, SIGUSR1);
				ft_printf("bit = 1\n");
			}
			else
			{
				kill(serv_pid, SIGUSR2);
				ft_printf("bit = 0\n");
			}
			pause();
			//usleep(100);
			if (valid)
				break;
			else
				repeat++;
		}
		if (repeat >= 10)
		{
			ft_error("Échec de la transmission\n");
		}
		i--;
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
	while(str[i])
	{
		usleep(500);
		send_to(str[i], serv_pid);
		i++;
	}
	return (0);
}
