/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:16:56 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/27 21:09:52 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("Error: wrong args\n");
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*tmp;
	t_pile	*b;

	if (argc <= 1)
		ft_error("Error: too few args\n");
	check_argv(argv);
	i = 0;
	a = NULL;
	b = NULL;
	while (i++ < (argc - 1))
	{
		tmp = pile_new(ft_atoi(argv[i]));
		pile_add_back(&a, tmp);
	}
	/*
	pile_print(&a, &b);
	rra(&a, &b);
	pile_print(&a, &b);
	rra(&a, &b);
	pile_print(&a, &b);
	rra(&a, &b);
	pile_print(&a, &b);
	sa(&a, &b);
	pile_print(&a, &b);
	ra(&a, &b);
	pile_print(&a, &b);
	ra(&a, &b);
	pile_print(&a, &b);
	*/
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	cost_calc(&a, &b);
	ft_printf("min val: %d\n", search_min(&a));
	pile_print(&a, &b);
	ft_printf("%d\n", is_sorted(&a));
	pile_clear(&a);
	pile_clear(&b);
	return (0);
}
