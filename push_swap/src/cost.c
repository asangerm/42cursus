/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:04 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/01 17:37:47 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_len	search_first_inf(t_pile **b, int val_a)
{
	t_pile	*first_b;
	t_len	i;

	first_b = *b;
	i.a = 0;
	i.b = 0;
	while (first_b)
	{
		if (val_a > first_b->val)
			if (first_b->val > i.b)
				i.b = first_b->val;
		first_b = first_b->next;
	}
	if (i.b == 0)
		i.b = get_max(b);
	first_b = *b;
	while (first_b)
	{
		if (i.b == first_b->val)
			return (i);
		i.a++;
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
	t_len	i;

	i = search_first_inf(b, a->val);
	if (i.a <= len.b / 2)
		a->cost += i.a;
	else
		a->cost += len.b - i.a;
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
