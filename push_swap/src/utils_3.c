/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:29:45 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/04 17:15:41 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free(args);
}

void	ft_error_2(char *str, char **argv)
{
	(void)str;
	ft_printf("%s", str);
	ft_free(argv);
	exit(0);
}

void	ft_check(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		check_argv_2(count_elts(argv), argv);
		ft_free(argv);
	}
	else
		check_argv(argc, argv);
}

void	init(t_pile **a, int argc, char **argv)
{
	t_pile	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = pile_new(ft_atoi(args[i]));
		pile_add_back(a, new);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	ft_error_pile(char *str, t_pile **a, t_pile **b)
{
	pile_clear(a);
	pile_clear(b);
	ft_printf("%s", str);
	exit(0);
}
