/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:46:22 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/16 21:44:21 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			temp = s;
		s++;
	}
	if (*s == (unsigned char)c)
		temp = s;
	return ((char *)temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	new = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[ft_strlen(s2) + ft_strlen(s1)] = '\0';
	return (new);
}
