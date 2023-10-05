/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:12:27 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/05 17:49:23 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	res = 0;
	i = 0;
	neg = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
		{
			neg = -1;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			return (res * neg);
		i++;
	}
	return (res * neg);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("ft_atoi : %d\natoi : %d\n", ft_atoi(argv[1]), atoi(argv[1]));
	return (0);
}
*/