# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 19:26:13 by asangerm          #+#    #+#              #
#    Updated: 2024/12/12 20:07:10 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp Span.cpp
OBJ		=	$(SRC:.cpp=.o)
CC		=	g++
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	test

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean $(NAME)