/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:44:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/16 13:12:05 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("salut, je suis le client! Mon pid est : %d\n", pid);
	return (0);
}
