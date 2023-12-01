/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:23:12 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/01 15:27:29 by asangerm         ###   ########.fr       */
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
	int	i;

	i = search_first_inf(b, (*a)->val);
	if (i != 0 && i != 1)
	{
		if (i <= len.b / 2)
			while ((*b)->val > (*a)->val)
				rb(a, b);
		else
			while (pile_last(b)->val < (*a)->val)
				rrb(a, b);
	}
}

void	change_b(t_pile **a, t_pile **b, t_len len)
{
	int	max;

	max = get_max(b);
	(void)len;
	if (!is_reverse_sorted(b))
	{
		if ((*b)->val < (*b)->next->val && (*b)->val > pile_last(b)->val)
			sb(a, b);
		else if ((*b)->val > (*b)->next->val && (*b)->val < pile_last(b)->val)
			while ((*b)->val != max)
				rrb(a, b);
		else
			rb(a, b);
	}
}

void	sort(t_pile **a, t_pile **b)
{
	int		min;
	t_len	len;

	pb(a, b);
	pb(a, b);
	pile_print(a, b);
	min = 0;
	while ((!is_sorted(a) || (*b)) && (*a))
	{
		set_zero(a);
		cost_calc(a, b);
		min = search_min(a);
		len = pile_len(a, b);
		pile_print(a, b);
		put_to_top(a, b, min, len);
		set_b(a, b, len);
		pb(a, b);
		change_b(a, b, len);
		pile_print(a, b);
	}
}
