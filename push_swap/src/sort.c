/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:23:12 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/01 17:38:03 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_to_top(t_pile **a, t_pile **b, int min, t_len len)
{
	t_pile	*first_a;
	int		i;

	first_a = *a;
	i = 0;
	while (first_a)
	{
		if (first_a->val == min)
			break ;
		i++;
		first_a = first_a->next;
	}
	first_a = *a;
	while (first_a->val != min)
	{
		if (i <= len.a / 2)
			ra(a, b);
		else
			rra(a, b);
		first_a = *a;
	}
}

void	set_b(t_pile **a, t_pile **b, t_len len)
{
	t_len	i;

	i = search_first_inf(b, (*a)->val);
	if (i.a != 0)
	{
		if (i.a <= len.b / 2)
			while ((*b)->val != i.b)
				rb(a, b);
		else
			while ((*b)->val != i.b)
				rrb(a, b);
	}
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
		put_to_top(a, b, min, len);
		set_b(a, b, len);
		pb(a, b);
	}
	while ((*b))
	{
		pa(a, b);
	}
}
