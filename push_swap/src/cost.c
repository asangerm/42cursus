/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:04 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/27 21:07:41 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_set(t_pile **a, t_pile **b, t_len i, t_len len)
{
	t_pile	*first_a;
	t_pile	*first_b;

	first_a = *a;
	first_b = *b;
	if (first_a->val < first_b->val && i.b < len.b / 2)
		first_a->cost += 1;
	if (first_a->val < first_b->val && i.b > len.b / 2)
		first_a->cost -= 1;
	*b = (*b)->next;
}

void	cost_calc(t_pile **a, t_pile **b)
{
	t_pile	*first_a;
	t_pile	*first_b;
	t_len	len;
	t_len	i;

	first_a = *a;
	len = pile_len(a, b);
	i.a = 0;
	while (first_a)
	{
		first_b = *b;
		i.b = 0;
		while (first_b)
		{
			cost_set(&first_a, &first_b, i, len);
			i.b++;
		}
		if (i.a <= len.a / 2)
			first_a->cost += i.a;
		else
			first_a->cost += len.a - i.a;
		first_a->cost += 1;
		first_a = first_a->next;
		i.a++;
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
