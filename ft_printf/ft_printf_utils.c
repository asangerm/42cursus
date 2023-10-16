/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:06:51 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/16 18:12:15 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		res += ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			res += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			res += ft_putnbr_fd(n / 10, fd);
			res += ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			res += ft_putchar_fd(n + '0', fd);
		}
	}
	return (res);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	res;

	res = 0;
	if (s == NULL)
	{
		res += ft_putstr_fd("(null)", 1);
		return (res);
	}
	while (*s)
	{
		res += ft_putchar_fd(*s, fd);
		s++;
	}
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
