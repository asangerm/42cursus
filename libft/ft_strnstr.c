/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:37:38 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/05 18:40:55 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
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

#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	const char *str;
	int			arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 2)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 3)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 4)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "", 10)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 5)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 6)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dol", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 7)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 8)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 9)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 10)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}