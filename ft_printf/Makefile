# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 16:40:14 by asangerm          #+#    #+#              #
#    Updated: 2023/10/16 16:11:47 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Werror -Wextra -Wall
AR			=	ar rcs
SRC			=	ft_printf.c ft_printf_utils.c
OBJ			=	$(SRC:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	$(AR) $(NAME) $(OBJ)


%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		: 
	rm -rf $(OBJ)

fclean		:	clean
	rm -rf $(NAME)

re			:	fclean all
