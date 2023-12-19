/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:28:12 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/19 13:31:25 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->e_dead = 0;
	data->e_full = 0;
}

void	set_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(data->writer), NULL);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philo[i].nb = i;
		data->philo[i].nb_eat = 0;
		data->philo[i].time_last_eat = 0;
		data->philo[i].data = data;
		data->philo[i].forks.left = i;
		data->philo[i].forks.right = (i + 1) % data->nb_philo;
		i++;
	}
}

void	set_threads(t_data *data)
{
	int		i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philo)
	{
		pthread_create(&(data->philo[i].id), NULL, routine, &(data->philo[i]));
		data->philo[i].time_last_eat = get_time();
		i++;
	}
	is_dead(data, data->philo);
	finish(data);
}
