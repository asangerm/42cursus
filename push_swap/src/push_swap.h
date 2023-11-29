/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:15:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/29 02:01:54 by asangerm         ###   ########.fr       */
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
	int				cost;
	struct s_pile	*next;
}		t_pile;

typedef struct s_len
{
	int	a;
	int	b;
}		t_len;

/* pile.c */

t_pile	*pile_new(int n);
t_pile	*pile_last(t_pile **pile);
void	pile_clear(t_pile **pile);
void	pile_iter(t_pile **pile, void (f)(int));
void	pile_add_back(t_pile **pile, t_pile *new);

/* pile_2.c */

void	set_zero(t_pile **pile);
int		is_sorted(t_pile **pile);
t_len	pile_len(t_pile **a, t_pile **b);
void	pile_print(t_pile **a, t_pile **b);
void	pile_add_front(t_pile **lst, t_pile *new);

/* utils.c */

void	ft_putnbr(int n);

/* rules.c */

void	swap(t_pile **pile);
void	rotate(t_pile **pile);
void	sa(t_pile **a, t_pile **b);
void	reverse_rotate(t_pile **pile);
void	push(t_pile **src, t_pile **dest);

/* rules_2.c */

void	sb(t_pile **a, t_pile **b);
void	ss(t_pile **a, t_pile **b);
void	pa(t_pile **a, t_pile **b);
void	pb(t_pile **a, t_pile **b);
void	ra(t_pile **a, t_pile **b);

/* rules_3.c */

void	rb(t_pile **a, t_pile **b);
void	rr(t_pile **a, t_pile **b);
void	rra(t_pile **a, t_pile **b);
void	rrb(t_pile **a, t_pile **b);
void	rrr(t_pile **a, t_pile **b);

/* cost.c */

int		search_min(t_pile **a);
void	cost_calc(t_pile **a, t_pile **b);
int		search_first_inf(t_pile **b, int val_a);
void	cost_to_go_top(t_pile *a, int i, t_len len);
void	cost_to_setup(t_pile *a, t_pile **b, t_len len);

/* sort.c */

void	sort(t_pile **a, t_pile **b);
void	put_to_top(t_pile **a, t_pile **b, int min, t_len len);

#endif