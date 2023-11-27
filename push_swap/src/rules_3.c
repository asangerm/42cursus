/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:43:30 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/27 15:46:49 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_pile **a, t_pile **b)
{
	rotate(b);
	(void)a;
	ft_printf("rb\n");
}

void	rr(t_pile **a, t_pile **b)
{
	rotate(b);
	rotate(a);
	ft_printf("rr\n");
}

void	rra(t_pile **a, t_pile **b)
{
	reverse_rotate(a);
	(void)b;
	ft_printf("rra\n");
}

void	rrb(t_pile **a, t_pile **b)
{
	reverse_rotate(b);
	(void)a;
	ft_printf("rrb\n");
}

void	rrr(t_pile **a, t_pile **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
