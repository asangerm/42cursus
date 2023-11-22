/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:09:33 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/22 14:08:24 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_f(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	bit;

	(void)context;
	if (sig == SIGUSR1)
	{
		bit = (bit << 1) | 1;
		usleep(200);
		kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		bit = (bit << 1);
		usleep(200);
		kill(info->si_pid, SIGUSR2);
	}
	i++;
	if (i == 8)
	{
		ft_printf("%c", (char)bit);
		i = 0;
		bit = 0;
	}
	usleep(100);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("salut, je suis le serveur! Mon pid est : %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_f;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}