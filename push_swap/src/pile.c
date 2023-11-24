/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:51:30 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/24 19:08:34 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_new(int n)
{
	t_pile	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new -> val = n;
	new -> next = NULL;
	return (new);
}

t_pile	*pile_last(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile -> next)
		pile = pile -> next;
	return (pile);
}

void	pile_add_back(t_pile **pile, t_pile *new)
{
	t_pile	*tmp;

	if (!*pile)
	{
		*pile = new;
		return ;
	}
	tmp = pile_last(*pile);
	tmp -> next = new;
}

void	pile_iter(t_pile *pile, void (f)(int))
{
	while (pile)
	{
		f(pile->val);
		pile = pile->next;
	}
}

void	pile_clear(t_pile **pile)
{
	t_pile	*tmp;

	while (*pile)
	{
		tmp = (*pile)-> next;
		free(*pile);
		(*pile) = tmp;
	}
}
