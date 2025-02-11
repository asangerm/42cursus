# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 18:15:11 by asangerm          #+#    #+#              #
#    Updated: 2025/02/11 18:19:30 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp RPN.cpp
OBJ		=	$(SRC:.cpp=.o)
CC		=	c++
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	RPN

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o	:	%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean $(NAME)