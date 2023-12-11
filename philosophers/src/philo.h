/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:07:26 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/11 14:53:30 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/src/libft.h"
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	left;
	pthread_mutex_t	right;
}		t_fork;

typedef struct s_philo
{
	pthread_t	id;
	t_fork		forks;
}		t_philo;

typedef struct s_data
{
	int		nb_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_eat;
	int		i;
	t_philo	*philo;
}		t_data;


#endif