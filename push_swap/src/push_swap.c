/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:16:56 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/04 13:58:08 by asangerm         ###   ########.fr       */
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
