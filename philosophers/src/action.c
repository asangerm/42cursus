/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:51 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/02 15:42:05 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data_ph;
	pthread_mutex_lock(&(data->forks[philo->fork.l]));
	pthread_mutex_lock(&(data->eat_m));
	print_action(data, philo->id_ph, "has taken a fork");
	pthread_mutex_unlock(&(data->eat_m));
	pthread_mutex_lock(&(data->forks[philo->fork.r]));
	pthread_mutex_lock(&(data->eat_m));
	print_action(data, philo->id_ph, "has taken a fork");
	print_action(data, philo->id_ph, "is eating");
	philo->last_eat_ph = stock_time();
	pthread_mutex_unlock(&(data->eat_m));
	sleep_time(data->t_eat, data);
	pthread_mutex_lock(&(data->eat_m));
	(philo->n_eat_ph)++;
	pthread_mutex_unlock(&(data->eat_m));
	pthread_mutex_unlock(&(data->forks[philo->fork.r]));
	pthread_mutex_unlock(&(data->forks[philo->fork.l]));
}

void	sleep_time(long long time, t_data *data)
{
	long long	i;

	i = stock_time();
	pthread_mutex_lock(&(data->eat_m));
	while ((!((stock_time() - i) >= time)) && !(data->is_dead))
	{
		pthread_mutex_unlock(&(data->eat_m));
		usleep(50);
		pthread_mutex_lock(&(data->eat_m));
	}
	pthread_mutex_unlock(&(data->eat_m));
}
