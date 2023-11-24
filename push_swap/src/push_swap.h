/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:15:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/24 22:24:39 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "../libft/src/libft.h"

/* structs */

typedef struct s_pile
{
	int				val;
	struct s_pile	*next;
}		t_pile;

/* pile.c */

t_pile	*pile_new(int n);
t_pile	*pile_last(t_pile **pile);
void	pile_clear(t_pile **pile);
void	pile_iter(t_pile **pile, void (f)(int));
void	pile_add_back(t_pile **pile, t_pile *new);

/* pile_2.c */

void	pile_print(t_pile **a, t_pile **b);
void	pile_add_front(t_pile **lst, t_pile *new);

/* utils.c */

void	ft_putnbr(int n);

/* rules.c */

void	swap(t_pile **pile);
void	rotate(t_pile **pile);
void	reverse_rotate(t_pile **pile);
void	push(t_pile **src, t_pile **dest);

#endif