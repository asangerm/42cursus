/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:07:26 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/19 13:38:33 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/src/libft.h"
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_fork
{
	int	left;
	int	right;
}		t_fork;

struct	s_data;

typedef struct s_philo
{
	pthread_t		id;
	int				nb;
	struct s_data	*data;
	t_fork			forks;
	int				nb_eat;
	long long		time_last_eat;
}		t_philo;

typedef struct s_data
{
	int				t_die;
	int				t_eat;
	int				nb_eat;
	int				e_dead;
	int				e_full;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writer;
	t_philo			*philo;
	int				t_sleep;
	int				nb_philo;
	long long		start_time;
}		t_data;

/* set.c */

void	set_mutex(t_data *data);
void	set_threads(t_data *data);
void	set_data(t_data *data, int argc, char **argv);

/* check .c */

void	check(int argc, char **argv);
void	check_death(int i, t_data *data, t_philo *ph);

/* utils.c */

long long	get_time(void);
void		ft_error(char *str);
void		print(t_data *data, int nb, char *str);

/* action.c */

void	eat(t_philo *philo);
void	*routine(void *arg);
void	sleep_(long long time, t_data *data);

/* philo.c */

void	finish(t_data *data);
int		main(int argc, char **argv);
void	is_dead(t_data *data, t_philo *ph);
void	init(t_data *data, int argc, char **argv);

#endif