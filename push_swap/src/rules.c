/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:11:13 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/24 22:57:40 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	t_pile	*first;
	int	tmp;

	if(!(*pile) || !(*pile)->next)
		return ;
	first = *pile;
	tmp = first->val;
	first->val = first->next->val;
	first->next->val = tmp;
}

void	rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*first;

	if (!(*pile) || !((*pile)->next))
		return ;
	last = pile_last(pile);
	first = (*pile)->next;
	last->next = *pile;
	(*pile)->next = NULL;
	*pile = first;
}

void	reverse_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*first;

	if (!(*pile) || !(pile_last(pile)))
		return ;
	last = *pile;
	while (last->next->next)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->next = *pile;
	*pile = first;
}

void	push(t_pile **src, t_pile **dest)
{
	t_pile	*to_add;
	t_pile	*new;

	if (*src)
	{
		to_add = *src;
		new = pile_new(to_add->val);
		*src = to_add->next;
		to_add->next = NULL;
		pile_add_front(dest, new);
		free(to_add);
	}
}
