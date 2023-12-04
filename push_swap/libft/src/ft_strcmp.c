/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:09:42 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/04 14:43:18 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*real_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	s1 = real_line(s1);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
