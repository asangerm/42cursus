/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:48:28 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/19 13:37:13 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dead(t_data *data, t_philo *ph)
{
	int	i;

	while (!(data->e_full))
	{
		i = 0;
		check_death(i, data, ph);
		if (data->e_dead)
			break ;
		while (data->nb_eat != -1 && i < data->nb_philo && ph[i].nb_eat >= data->nb_eat)
			i++;
		if (i == data->nb_philo)
			data->e_full = 1;
	}
}

void	finish(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = data->philo;
	if(data->nb_philo == 1)
		pthread_mutex_unlock(&(data->forks[0]));
	while (i < data->nb_philo)
	{
		pthread_join(ph[i].id, NULL);
		i++;
	}
	i = 0;
	usleep(1000);
	/*while (i < data->nb_philo)
	{
		pthread_mutex_unlock(&(data->forks[i]));
		pthread_mutex_destroy(&(data->forks[i]));
	}
	*/
	pthread_mutex_destroy(&(data->writer));
	free(data->philo);
	free(data->forks);
	exit (0);
}

void	init(t_data *data, int argc, char **argv)
{
	set_data(data, argc, argv);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	set_mutex(data);
	set_threads(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check(argc, argv);
	init(&data, argc, argv);
	return (0);
}
