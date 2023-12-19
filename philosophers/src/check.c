/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:31:02 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/19 13:33:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 6 || argc < 5)
		ft_error("Error wrong args\n");
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				ft_error("Error only digit args\n");
			j++;
		}
		if(ft_atoi(argv[i]) <= 0)
			ft_error("Error only positives args\n");
		i++;
	}
}

void	check_death(int i, t_data *data, t_philo *ph)
{
	int	j;

	j = 0;
	while (i < data->nb_philo && !(data->e_dead))
	{
		if ((get_time() - ph[i].time_last_eat) > data->t_die)
		{
			print(data, i, "is dead");
			data->e_dead = 1;
		}
		if(ph[i].nb_eat >= 1 && data->nb_eat == -1)
			j++;
		usleep(100);
		i++;
	}
	if (j >= data->nb_philo)
		data->e_full = 1;
}
