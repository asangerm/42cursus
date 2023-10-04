/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:37:38 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/04 19:01:22 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char *)str;
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0] && ft_strncmp(str + i, to_find, len - i) == 0)
		{
			return (temp + i);
		}
		i++;
	}
	return ("\0");
}
