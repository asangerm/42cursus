/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:32:50 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/21 17:26:57 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, int nb, char *msg)
{
	pthread_mutex_lock(&(data->write_m));
	if (!(data->is_dead))
		printf("%4lli %i %s\n", stock_time() - data->start, nb, msg);
	pthread_mutex_unlock(&(data->write_m));
}

long long	stock_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}

long int	actual_time(void)
{
	struct timeval		current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		ft_error("gettimeofday error\n");
	return (current_time.tv_usec);
}
