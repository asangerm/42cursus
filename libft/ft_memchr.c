/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:42:14 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/03 19:17:59 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (*(unsigned char *)s && i < n)
	{
		if (*(unsigned char *)s == c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	void	*temp;
	if (argc == 4)
	{
		temp = ft_memchr((const void *)argv[1], argv[2][0], (size_t)atoi(argv[3]));
		printf("%ld\n", (char *)temp - argv[1]);
	}
	return (0);
}
*/