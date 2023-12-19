/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:51 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/19 13:35:40 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_(long long time, t_data *data)
{
	long long	i;

	i = get_time();
	while ((!((get_time() - i) >= time)) && !(data->e_dead))
		usleep(50);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->forks.left]));
	print(data, philo->nb, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->forks.right]));
	print(data, philo->nb, "has taken a fork");
	print(data, philo->nb, "is eating");
	philo->time_last_eat = get_time();
	sleep_(data->t_eat, data);
	philo->nb_eat++;
	pthread_mutex_unlock(&(data->forks[philo->forks.left]));
	pthread_mutex_unlock(&(data->forks[philo->forks.right]));
}

void	*routine(void *arg)
{
	t_philo		*ph;
	t_data		*data;
	int			i;

	i = 0;
	ph = (t_philo *)arg;
	data = ph->data;
	//if (ph->nb % 2 == 0)
		//usleep(1500);
	while (!(data->e_dead) && !(data->e_full))
	{
		eat(ph);
		print(data, ph->nb, "is sleeping");
		sleep_(data->t_sleep, data);
		print(data, ph->nb, "is thinking");
		i++;
	}
	return (NULL);
}
