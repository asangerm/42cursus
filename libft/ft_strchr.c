/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:33:23 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/03 16:47:15 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*temp;
	if (argc == 3)
	{
		temp = ft_strchr(argv[1], argv[2][0]);
		printf("%ld\n", temp - argv[1]);
	}
	return (0);
}
*/