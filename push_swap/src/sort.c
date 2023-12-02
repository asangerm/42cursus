/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:23:12 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/01 22:36:29 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_sign(t_pile **a, t_pile **b, t_len len)
{
	t_pile	*first;
	int		i;

	first = *a;
	i = 0;
	while (first)
	{
		if (i <= len.a / 2)
			first->cost = i;
		else
			first->cost = i - len.a;
		first = first->next;
		i++;
	}
	first = *b;
	i = 0;
	while (first)
	{
		if (i <= len.b / 2)
			first->cost = i;
		else
			first->cost = i - len.b;
		first = first->next;
		i++;
	}
}

int	get_cost(t_pile **pile, int val)
{
	t_pile	*first;

	first = *pile;
	while (first)
	{
		if (first->val == val)
			return (first->cost);
		first = first->next;
	}
	return (0);
}

void	put_to_top(t_pile **a, t_pile **b, int min, t_len len)
{
	int	val_b;

	val_b = search_first_inf(b, min);
	while ((*a)->val != min)
	{
		if (get_cost(a, min) > 0)
		{
			if (get_cost(b, val_b) > 0)
				rr(a, b);
			else
				ra(a, b);
		}
		else if (get_cost(a, min) < 0 && get_cost(b, val_b) < 0)
			rrr(a, b);
		else
			rra(a, b);
		set_sign(a, b, len);
	}
	if (get_cost(b, val_b) > 0)
		while ((*b)->val != val_b)
			rb(a, b);
	else
		while ((*b)->val != val_b)
			rrb(a, b);
}

void	sort(t_pile **a, t_pile **b)
{
	int		min;
	t_len	len;

	pb(a, b);
	pb(a, b);
	min = 0;
	while ((!is_sorted(a) || (*b)) && (*a))
	{
		set_zero(a);
		cost_calc(a, b);
		min = search_min(a);
		len = pile_len(a, b);
		set_sign(a, b, len);
		put_to_top(a, b, min, len);
		pb(a, b);
	}
	min = get_max(b);
	if (get_cost(b, min) > 0)
		while ((*b)->val != min)
			rb(a, b);
	else
		while ((*b)->val != min)
			rrb(a, b);
	while ((*b))
		pa(a, b);
}
