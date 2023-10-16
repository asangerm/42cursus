/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:09:11 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/16 16:53:08 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_base(unsigned long nb, char *base)
{
	unsigned int	l;
	int				res;

	res = 0;
	l = 16;
	if (nb >= l)
	{
		res += ft_convert_base(nb / l, base);
		res += ft_convert_base(nb % l, base);
	}
	else
	{
		res += ft_putchar_fd(base[nb], 1);
	}
	return (res);
}

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int	res;

	res = 0;
	if (n >= 10)
	{
		res += ft_putnbr_fd(n / 10, fd);
		res += ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		res += ft_putchar_fd(n + '0', fd);
	}
	return (res);
}

int	ft_hexconvert(unsigned long int n, char c)
{
	char	*base;
	int		res;

	res = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (c == 'p')
	{
		if (n == 0)
		{
			res += ft_putstr_fd("(nil)")
		}
		res += ft_putstr_fd("0x", 1);
	}
	res += ft_convert_base(n, base);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				res += ft_putchar_fd(va_arg(args, int), 1);
			if (*format == 'u')
				ft_putunsigned_fd(va_arg(args, unsigned int), 1);
			if (*format == 'i' || *format == 'd')
				res += ft_putnbr_fd(va_arg(args, int), 1);
			if (*format == 's')
				res += ft_putstr_fd(va_arg(args, char *), 1);
			if (*format == '%')
				res += ft_putchar_fd('%', 1);
			if (*format == 'x' || *format == 'X' || *format == 'p')
				res += ft_hexconvert(va_arg(args, unsigned long int), *format);
		}
		else
			res += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (res);
}
