/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:59:57 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/29 01:21:27 by asangerm         ###   ########.fr       */
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

int	is_sorted(t_pile **pile)
{
	t_pile	*first;

	first = *pile;
	while (first)
	{
		if (first->next && first->val > first->next->val)
			return (0);
		first = first->next;
	}
	return (1);
}

t_len	pile_len(t_pile **a, t_pile **b)
{
	t_pile	*first;
	t_len	len;

	first = *a;
	len.a = 0;
	while (first)
	{
		first = first->next;
		len.a++;
	}
	first = *b;
	len.b = 0;
	while (first)
	{
		first = first->next;
		len.b++;
	}
	return (len);
}

void	set_zero(t_pile **pile)
{
	t_pile	*first;

	first = *pile;
	while (first)
	{
		first->cost = 0;
		first = first->next;
	}
}
