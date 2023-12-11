/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:05:18 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/11 16:04:38 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	*func(void *arg)
{
	pthread_t tid;
	t_data	*data;

	data = (t_data *)arg;
	tid = pthread_self();
	pthread_mutex_lock(&data->philo[data->i].forks.left);
	pthread_mutex_lock(&data->philo[data->i].forks.right);
	ft_printf("Thread [%d]\n", tid);
	pthread_mutex_unlock(&data->philo[data->i].forks.left);
	pthread_mutex_unlock(&data->philo[data->i].forks.right);
	return (NULL);
}

void	init(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	data->i = 0;
	while(data->i < data->nb_philo)
	{
		if (data->i == data->nb_philo - 1)
		{
			data->philo[data->i].forks.left = data->philo[data->i - 1].forks.right;
			data->philo[data->i].forks.right = data->philo[0].forks.left;
		}
		else
		{
			if (data->i == 0)
				pthread_mutex_init(&data->philo[data->i].forks.left, NULL);
			else
				data->philo[data->i].forks.left = data->philo[data->i - 1].forks.right;
			pthread_mutex_init(&data->philo[data->i].forks.right, NULL);
		}
		pthread_create(&data->philo[data->i].id, NULL, func, data);
		data->i++;
	}
}

void	join(t_data *data)
{
	data->i = 0;
	while (data->i < data->nb_philo)
	{
		pthread_join(data->philo[data->i].id, NULL);
		data->i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 6 || argc < 5)
		ft_error("Error wrong args\n");
	init(&data, argc, argv);
	join(&data);
	return (0);
}