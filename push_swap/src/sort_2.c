/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:51:09 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/02 00:57:22 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_pile **a, t_pile **b)
{
	if (is_sorted(a))
		return ;
	sa(a, b);
}

void	sort_3(t_pile **a, t_pile **b)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val < pile_last(a)->val)
		sa(a, b);
	if ((*a)->next->val > pile_last(a)->val)
		rra(a, b);
	else if ((*a)->val > (*a)->next->val && (*a)->val < pile_last(a)->val)
		ra(a, b);
	if ((*a)->val > (*a)->next->val)
		sa(a, b);
	if (is_sorted(a))
		return ;
	rra(a, b);
	sa(a, b);
}

int	get_min(t_pile **a)
{
	t_pile	*f;
	int		min;

	f = *a;
	min = f->val;
	while (f)
	{
		if (f->val < min)
			min = f->val;
		f = f->next;
	}
	return (min);
}

void	sort_5(t_pile **a, t_pile **b)
{
	while ((*a)->val != get_min(a))
		rra(a, b);
	pb(a, b);
	while ((*a)->val != get_min(a))
		rra(a, b);
	pb(a, b);
	sort_3(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_inf_5(t_pile **a, t_pile **b)
{
	if (pile_len(a, b).a == 2)
		sort_2(a, b);
	if (pile_len(a, b).a == 3)
		sort_3(a, b);
	if (pile_len(a, b).a == 5)
		sort_5(a, b);
}
