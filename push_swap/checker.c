/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:37:16 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/04 14:39:24 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"

int	do_it_2(char *line, t_pile **a, t_pile **b)
{
	if (!(ft_strcmp(line, "ss")))
	{
		swap(a);
		swap(b);
	}
	else if (!(ft_strcmp(line, "rr")))
	{
		rotate(a);
		rotate(b);
	}
	else if (!(ft_strcmp(line, "rrr")))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	do_it(char *line, t_pile **a, t_pile **b)
{
	if (!(ft_strcmp(line, "sa")))
		swap(a);
	else if (!(ft_strcmp(line, "sb")))
		swap(b);
	else if (!(ft_strcmp(line, "pa")))
		push(b, a);
	else if (!(ft_strcmp(line, "pb")))
		push(a, b);
	else if (!(ft_strcmp(line, "ra")))
		rotate(a);
	else if (!(ft_strcmp(line, "rb")))
		rotate(b);
	else if (!(ft_strcmp(line, "rra")))
		reverse_rotate(a);
	else if (!(ft_strcmp(line, "rrb")))
		reverse_rotate(b);
	else if (!do_it_2(line, a, b))
		return (0);
	return (1);
}

void	print_checker_res(t_pile **a, t_pile **b)
{
	if (is_sorted(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (*a)
		pile_clear(a);
	if (*b)
		pile_clear(b);
}

void	check(t_pile **a, t_pile **b)
{
	char	*line;

	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		if (!do_it(line, a, b))
		{
			free(line);
			ft_error_pile("Error", a, b);
			return ;
		}
		if (is_sorted(a) && !(*b))
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line (0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	ft_check(argc, argv);
	init(&a, argc, argv);
	check(&a, &b);
	print_checker_res(&a, &b);
	return (0);
}
