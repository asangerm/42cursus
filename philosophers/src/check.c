/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:31:02 by asangerm          #+#    #+#             */
/*   Updated: 2024/02/13 17:42:53 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_error("Error, program needs 5 or 6 args");
	if (!check_value(argc, argv))
		ft_error("Error, args are not digit");
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		ft_error("Error, args not positive");
}

void	check_eat_death(int i, t_data *data, t_philo *ph)
{
	while (++i < data->n_philo && !(data->is_dead))
	{
		pthread_mutex_lock(&(data->eat_m));
		if ((stock_time() - ph[i].last_eat_ph) > data->t_die)
			print_action(data, i + 1, "is dead");
		if ((stock_time() - ph[i].last_eat_ph) > data->t_die)
			data->is_dead = 1;
		pthread_mutex_unlock(&(data->eat_m));
		usleep(100);
	}
}

void	is_dead(t_data *data, t_philo *ph)
{
	int	i;

	while (1)
	{
		i = -1;
		check_eat_death(i, data, ph);
		if (data->is_dead)
			break;
		i = 0;
		pthread_mutex_lock(&(data->eat_m));
		while (data->meal_n != -1 && i < data->n_philo
			&& ph[i].n_eat_ph >= data->meal_n)
			i++;
		if (i == data->n_philo)
			{
				data->have_ate = 1;
				pthread_mutex_unlock(&(data->eat_m));
				finish(data);
				pthread_mutex_lock(&(data->eat_m));
			}
		pthread_mutex_unlock(&(data->eat_m));
	}
}
