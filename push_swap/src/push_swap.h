/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:15:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/24 19:53:21 by asangerm         ###   ########.fr       */
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
t_pile	*pile_last(t_pile *pile);
void	pile_clear(t_pile **pile);
void	pile_iter(t_pile *pile, void (f)(int));
void	pile_add_back(t_pile **pile, t_pile *new);

/* utils.c */

void	ft_putnbr(int n);

#endif