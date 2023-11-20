/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:09:33 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/20 14:24:02 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_f(int sig)
{
	ft_printf("signal delivered, the signal is: %d\n", sig);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("salut, je suis le serveur! Mon pid est : %d\n", pid);

	signal(SIGUSR1, signal_f);
	signal(SIGUSR2, signal_f);

	while (1)
		sleep(1);
	return (0);
}

