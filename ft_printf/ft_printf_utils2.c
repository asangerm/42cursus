/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:11:50 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/16 18:35:10 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	void	*temp;

	temp = s;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = c;
		i++;
		s++;
	}
	return (temp);
}

int	ft_format(const char format, va_list args)
{
	int	res;

	res = 0;
	if (format == 'c')
		res += ft_putchar_fd(va_arg(args, int), 1);
	if (format == 'u')
		res += ft_putunsigned_fd(va_arg(args, unsigned int), 1);
	if (format == 'i' || format == 'd')
		res += ft_putnbr_fd(va_arg(args, int), 1);
	if (format == 's')
		res += ft_putstr_fd(va_arg(args, char *), 1);
	if (format == '%')
		res += ft_putchar_fd('%', 1);
	if (format == 'x' || format == 'X' || format == 'p')
		res += ft_hexconvert(va_arg(args, unsigned long int), format);
	return (res);
}
