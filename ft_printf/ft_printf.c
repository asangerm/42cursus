/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:09:11 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/14 15:25:02 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_base(unsigned long int nb, char *base, char *nbrchar, int *i)
{
	unsigned int	l;

	l = 16;
	if (nb >= l)
	{
		ft_convert_base(nb / l, base, nbrchar, i);
		ft_convert_base(nb % l, base, nbrchar, i);
	}
	else
	{
		nbrchar[*i] = base[nb];
		*i += 1;
	}
}

static void	ft_hexconvert(unsigned long int n, char c)
{
	char	*base;
	char	*result;
	int		i;

	result = ft_calloc(sizeof(char), 16 + 1);
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (c == 'p')
		ft_putstr_fd("0x", 1);
	i = 0;
	ft_convert_base(n, base, result, &i);
	ft_putstr_fd(result, 1);
	free(result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (*format == 'i' || *format == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (*format == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (*format == '%')
				write(1, "%", 1);
			if (*format == 'x' || *format == 'X' || *format == 'p')
				ft_hexconvert(va_arg(args, unsigned long int), *format);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	ft_printf("%p\n", &i);
	printf("%p\n", &i);
}
