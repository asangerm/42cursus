# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 16:40:14 by asangerm          #+#    #+#              #
#    Updated: 2023/10/13 17:12:20 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Werror -Wextra -Wall
AR			=	ar rcs
SRC			=	ft_printf.c
OBJ			=	$(SRC:%.c=%.o)
LIBFT		=	libft/libft.a

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT)	:
	make all -C libft

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		: 
	rm -rf $(OBJ) $(BONUS_OBJ)
	make clean -C libft

fclean		:	clean
	rm -rf $(NAME)
	make fclean -C libft

re			:	fclean all
