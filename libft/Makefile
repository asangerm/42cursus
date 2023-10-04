# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 16:40:14 by asangerm          #+#    #+#              #
#    Updated: 2023/10/04 16:53:36 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wextra -Wall
AR = ar rcs
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(AR) $@ $^

all : $(NAME)

clean : 
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME)

re : clean fclean all
