/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:00:36 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/04 14:56:15 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elts(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	check_dupe_2(int argc, char **argv)
{
	int	len;
	int	*tab;
	int	i;

	len = argc;
	tab = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (ft_atoi_long(argv[i]) >= 2147483647)
		{
			free(tab);
			ft_error_2("Error\n", argv);
		}
		if (is_in(tab, i, ft_atoi(argv[i])))
		{
			free(tab);
			ft_error_2("Error\n", argv);
		}
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	free(tab);
}

void	check_argv_2(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc <= 0)
		ft_error_2("", argv);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error_2("Error\n", argv);
			j++;
		}
		i++;
	}
	check_dupe_2(argc, argv);
}

void	main_2(char **argv)
{
	int		i;
	t_pile	*a;
	t_pile	*tmp;
	t_pile	*b;

	argv = ft_split(argv[1], ' ');
	check_argv_2(count_elts(argv), argv);
	i = 0;
	a = NULL;
	b = NULL;
	while (argv[i])
	{
		tmp = pile_new(ft_atoi(argv[i]));
		pile_add_back(&a, tmp);
		i++;
	}
	set_zero(&a);
	if (pile_len(&a, &b).a <= 5)
		sort_inf_5(&a, &b);
	if (!is_sorted(&a))
		sort(&a, &b);
	ft_free(argv);
	pile_clear(&a);
	pile_clear(&b);
	exit (0);
}
