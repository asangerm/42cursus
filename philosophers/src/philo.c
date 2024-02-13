/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:48:28 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/13 18:00:55 by asangerm         ###   ########.fr       */
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

long int	actual_time(void)
{
	struct timeval		current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		ft_error("gettimeofday error\n");
	return (current_time.tv_usec);
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
