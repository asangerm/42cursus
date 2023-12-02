/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:04 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/01 22:36:48 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_first_inf(t_pile **b, int val_a)
{
	t_pile	*first_b;
	int		val_b;

	first_b = *b;
	val_b = 0;
	while (first_b)
	{
		if (val_a > first_b->val)
			if (first_b->val > val_b)
				val_b = first_b->val;
		first_b = first_b->next;
	}
	if (val_b == 0)
		val_b = get_max(b);
	return (val_b);
}

int	get_tall(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	cost_to_setup(t_pile **a, t_pile *node_a, t_pile **b)
{
	int	cost_b;
	int	cost_a;

	cost_a = get_cost(a, node_a->val);
	cost_b = get_cost(b, search_first_inf(b, node_a->val));
	if (cost_a >= 0)
	{
		if (cost_b >= 0)
			node_a->cost = get_tall(cost_a, cost_b);
		else
			node_a->cost = cost_a + cost_b * -1;
	}
	else if (cost_a < 0)
	{
		if (cost_b < 0)
			node_a->cost = get_tall(cost_a * -1, cost_b * -1);
		else
			node_a->cost = cost_b + cost_a * -1;
	}
}

void	cost_calc(t_pile **a, t_pile **b)
{
	t_pile	*first_a;
	t_len	len;

	first_a = *a;
	len = pile_len(a, b);
	set_sign(a, b, len);
	while (first_a)
	{
		cost_to_setup(a, first_a, b);
		first_a->cost += 1;
		first_a = first_a->next;
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
