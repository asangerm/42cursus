# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 11:25:47 by asangerm          #+#    #+#              #
#    Updated: 2023/12/04 14:41:43 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME	=	push_swap
CHECKER	=	checker

# Flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LM		=	-lm

# Directories
SRC_DIR	=	src/
OBJ_DIR	=	obj/
LIB_DIR	=	libft/

# .c and .o files
SRC		=	$(wildcard $(SRC_DIR)*.c)
SRC_BON	=	checker.c
OBJ		=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
OBJ_BON	=	checker.o
OBJ_ESS	=	\
	obj/push_swap.o obj/pile.o obj/pile_2.o obj/utils_3.o \
	obj/utils.o obj/utils_2.o obj/sort_2.o obj/rules_2.o obj/rules.o \
	obj/sort.o obj/rules_3.o obj/cost.o

# .a files
LIBFT	=	$(LIB_DIR)libft.a

# The main rule
all				:	$(NAME)

bonus			:	$(NAME) $(CHECKER) 

# The name rule
$(NAME)			:	$(OBJ) $(LIBFT)
	@echo "\033[0;33mCompiling the whole project -> ⏳\033[0m"
	@$(CC) $(OBJ) $(LIBFT) -o $@
	@echo "\033[0;32mProject successfuly compiled -> ✅\033[0m\n"

# The checker rule
$(CHECKER)			:	$(OBJ) $(LIBFT) $(SRC_BON)
	@echo "\033[0;33mCompiling bonus -> ⏳\033[0m"
	@$(CC) $(SRC_BON) $(OBJ_ESS) $(LIBFT) -o $@
	@echo "\033[0;32mProject bonus -> ✅\033[0m\n"

# The libft rule
$(LIBFT)		:	$(LIB_DIR)
	@echo "\033[0;33mCompiling libft -> ⏳\033[0m"
	@make all -sC $<
	@echo "\033[0;32mLibft successfuly compiled -> ✅\033[0m\n"

# Compile .c to .o files
$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "\033[0;33mCompiling project src -> ⏳\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mSrc's project successfuly compiled -> ✅\033[0m\n"

# Create the obj directory
$(OBJ_DIR)		:
	@mkdir -p $@

# Clean, fclean and re rules
clean			:
	@echo "\033[0;31mCleaning obj files -> 🗑️\033[0m"
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)
	@echo "\033[0;32mDone -> ✅\033[0m\n"

fclean			:	clean
	@echo "\033[0;31mCleaning program -> 🗑️\033[0m"
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)
	@make fclean -sC $(LIB_DIR)
	@echo "\033[0;32mDone -> ✅\033[0m\n"

re				:	fclean all

