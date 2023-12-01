/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:53:30 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/01 15:26:47 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			ft_putchar(n + '0');
		}
	}
}

int	is_reverse_sorted(t_pile **pile)
{
	t_pile	*first;

	first = *pile;
	while (first)
	{
		if (first->next && first->val < first->next->val)
			return (0);
		first = first->next;
	}
	return (1);
}

int	get_max(t_pile **pile)
{
	int		max;
	t_pile	*tmp;

	max = 0;
	tmp = *pile;
	while (tmp)
	{
		if (tmp->val > max)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}
