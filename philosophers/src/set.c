/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:28:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/02 15:49:50 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
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

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	finish(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = data->philos;
	if (data->n_philo == 1)
		pthread_mutex_unlock(&(data->forks[ph[0].fork.l]));
	/*while (i < data->n_philo)
	{
		pthread_join(ph[i].n_thread, NULL);
		i++;
	}*/
	i = 0;
	while (++i < data->n_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write_m));
	pthread_mutex_destroy(&(data->eat_m));
	free(data->forks);
	free(data->philos);
	exit (0);
}
