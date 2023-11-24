/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:59:57 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/24 22:27:31 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pile_add_front(t_pile **lst, t_pile *new)
{
	new->next = *lst;
	*lst = new;
}

void	pile_print(t_pile **a, t_pile **b)
{
	ft_printf("Pile a: ");
	pile_iter(a, ft_putnbr);
	ft_printf("\n");
	ft_printf("Pile b: ");
	pile_iter(b, ft_putnbr);
	ft_printf("\n");
}
