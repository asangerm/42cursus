/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:04 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/29 01:21:41 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_first_inf(t_pile **b, int val_a)
{
	t_pile	*first_b;
	int		i;

	first_b = *b;
	i = 0;
	while (first_b)
	{
		if (val_a < first_b->val)
			i++;
		first_b = first_b->next;
	}
	return (i);
}

void	cost_to_go_top(t_pile *a, int i, t_len len)
{
	if (i <= len.a / 2)
		(a)->cost += i;
	else
		(a)->cost += (len.a - i);
}

void	cost_to_setup(t_pile *a, t_pile **b, t_len len)
{
	int	i;

	i = search_first_inf(b, a->val);
	if (i != 0)
	{
		if (i < len.b / 2)
			a->cost += (2 * i + 1);
		else
			a->cost += (2 * (len.b - i) + 1);
	}
}

void	cost_calc(t_pile **a, t_pile **b)
{
	t_pile	*first_a;
	t_len	len;
	int		i;

	first_a = *a;
	len = pile_len(a, b);
	i = 0;
	while (first_a)
	{
		cost_to_setup(first_a, b, len);
		cost_to_go_top(first_a, i, len);
		first_a->cost += 1;
		first_a = first_a->next;
		i++;
	}
}

int	search_min(t_pile **a)
{
	int		min_cost;
	int		min_val;
	t_pile	*f;

	min_cost = 1000;
	min_val = 0;
	f = *a;
	while (f)
	{
		if (f->cost < min_cost)
		{
			min_cost = f->cost;
			min_val = f->val;
		}
		f = f->next;
	}
	return (min_val);
}
