/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:10 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/04 13:58:25 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*tmp;
	t_pile	*b;

	if (argc == 2)
		main_2(argv);
	check_argv(argc, argv);
	i = 0;
	a = NULL;
	b = NULL;
	while (i++ < (argc - 1))
	{
		tmp = pile_new(ft_atoi(argv[i]));
		pile_add_back(&a, tmp);
	}
	set_zero(&a);
	if (pile_len(&a, &b).a <= 5)
		sort_inf_5(&a, &b);
	if (!is_sorted(&a))
		sort(&a, &b);
	pile_clear(&a);
	pile_clear(&b);
	return (0);
}
