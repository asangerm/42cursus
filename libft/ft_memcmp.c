/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:11:55 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/04 15:29:01 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < (n - 1) && *(char *)s1 && *(char *)s2)
	{
		if (*(char *)s1 > *(char *)s2)
			return (1);
		if (*(char *)s1 < *(char *)s2)
			return (-1);
		i++;
		s1++;
		s2++;
	}
	if (*(char *)s1 > *(char *)s2)
		return (1);
	else if (*(char *)s1 < *(char *)s2)
		return (-1);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%d\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
		printf("%d\n", memcmp(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
*/