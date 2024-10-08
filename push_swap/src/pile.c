/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:51:30 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/27 19:57:10 by asangerm         ###   ########.fr       */
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

t_pile	*pile_last(t_pile **pile)
{
	t_pile	*new;

	new = *pile;
	if (!new)
		return (NULL);
	while (new->next)
		new = new->next;
	return (new);
}

void	pile_add_back(t_pile **pile, t_pile *new)
{
	t_pile	*tmp;

	if (!*pile)
	{
		*pile = new;
		return ;
	}
	tmp = pile_last(pile);
	tmp -> next = new;
}

void	pile_iter(t_pile **pile, void (f)(int))
{
	t_pile	*tmp;

	tmp = *pile;
	while (tmp)
	{
		f(tmp->val);
		ft_printf(":");
		f(tmp->cost);
		ft_printf(" ");
		tmp = tmp->next;
	}
}

void	pile_clear(t_pile **pile)
{
	t_pile	*current;
	t_pile	*next;

	current = *pile;
	while (current)
	{
		next = current-> next;
		free(current);
		current = next;
	}
	*pile = NULL;
}
