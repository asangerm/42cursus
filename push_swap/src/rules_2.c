/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:26 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/27 15:49:29 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_pile **a, t_pile **b)
{
	(void)a;
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_pile **a, t_pile **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_pile **a, t_pile **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_pile **a, t_pile **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	ra(t_pile **a, t_pile **b)
{
	rotate(a);
	(void)b;
	ft_printf("ra\n");
}
