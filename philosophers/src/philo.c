/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:48:28 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/21 16:41:29 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	set_data(argc, argv, &data);
	init(&data);
	return (0);
}

void	init(t_data *data)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = data->philos;
	data->start = stock_time();
	while (i < data->n_philo)
	{
		pthread_create(&(ph[i].n_thread), NULL, life, &(ph[i]));
		pthread_mutex_lock(&(data->eat_m));
		ph[i].last_eat_ph = stock_time();
		pthread_mutex_unlock(&(data->eat_m));
		i++;
	}
	is_dead(data, ph);
	finish(data);
}
