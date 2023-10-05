/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:33:52 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/04 13:58:32 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*temp;

	temp = dest;
	i = 0;
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		i++;
		dest++;
		src++;
	}
	return (temp);
}
