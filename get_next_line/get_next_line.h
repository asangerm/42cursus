/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:43:54 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/17 17:56:21 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*ft_newstr(char *str);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strlen_endl(char	*str);
char	*ft_the_real_line(char *str);
char	*ft_strrchr(const char *s, int c);
char	*ft_a_next_line(int fd, char *str);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif