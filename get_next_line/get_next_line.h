/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:43:54 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/16 21:15:57 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_newstr(char *str);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strlen_endl(char	*str);
char	*ft_the_real_line(char *str);
char	*ft_strrchr(const char *s, int c);
char	*ft_a_next_line(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif