/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:51 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/21 17:26:29 by asangerm         ###   ########.fr       */
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

void	*life(void *philo)
{
	t_philo		*ph;
	t_data		*data;
	int			i;

	i = 0;
	ph = (t_philo *)philo;
	data = ph->data_ph;
	if (ph->id_ph % 2 == 0)
		usleep(1500);
	pthread_mutex_lock(&(data->eat_m));
	while (!(data->is_dead) && data->have_ate != 1)
	{
		pthread_mutex_unlock(&(data->eat_m));
		eat(ph);
		pthread_mutex_lock(&(data->eat_m));
		print_action(data, ph->id_ph, "is sleeping");
		pthread_mutex_unlock(&(data->eat_m));
		sleep_time(data->t_sleep, data);
		pthread_mutex_lock(&(data->eat_m));
		print_action(data, ph->id_ph, "is thinking");
		i++;
	}
	pthread_mutex_unlock(&(data->eat_m));
	return (NULL);
}

void	finish(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = data->philos;
	if (data->n_philo == 1)
		pthread_mutex_unlock(&(data->forks[ph[0].fork.l]));
	while (i < data->n_philo)
	{
		pthread_join(ph[i].n_thread, NULL);
		i++;
	}
	i = 0;
	while (++i < data->n_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write_m));
	pthread_mutex_destroy(&(data->eat_m));
	free(data->forks);
	free(data->philos);
	exit (0);
}
