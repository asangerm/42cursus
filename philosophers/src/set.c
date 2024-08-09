/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:28:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/13 18:00:24 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->have_ate = 0;
	if (argc == 6)
		data->meal_n = ft_atoi(argv[5]);
	else
		data->meal_n = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	set_mutex_thread(data);
	init(data);
}

void	set_mutex_thread(t_data *data)
{
	int	i;

	i = data->n_philo;
	data->is_dead = 0;
	pthread_mutex_init(&(data->write_m), NULL);
	pthread_mutex_init(&(data->eat_m), NULL);
	while (--i >= 0)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].id_ph = i + 1;
		data->philos[i].n_eat_ph = 0;
		data->philos[i].fork.l = i;
		data->philos[i].fork.r = (i + 1) % data->n_philo;
		data->philos[i].last_eat_ph = 0;
		data->philos[i].data_ph = data;
	}
}
