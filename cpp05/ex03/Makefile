# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 16:10:22 by asangerm          #+#    #+#              #
#    Updated: 2024/12/07 23:27:39 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
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