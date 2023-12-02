/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:16:56 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/02 20:10:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

int	is_in(int *tab, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == val)
			return (1);
		i++;
	}
	return (0);
}

void	check_dupe(int argc, char **argv)
{
	int	len;
	int	*tab;
	int	i;

	len = argc - 1;
	tab = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (ft_atoi_long(argv[i + 1]) >= 2147483647)
		{
			free(tab);
			ft_error("Error\n");
		}
		if (is_in(tab, i, ft_atoi(argv[i + 1])))
		{
			free(tab);
			ft_error("Error\n");
		}
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	free(tab);
}

void	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 1)
		ft_error("");
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
	check_dupe(argc, argv);
}

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
