# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 11:25:47 by asangerm          #+#    #+#              #
#    Updated: 2023/11/16 11:43:23 by asangerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names of the programs
SERVER	=	server
CLIENT	=	client

# Flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LM		=	-lm

# Directories
DIR_SERV		=	server_file/
SRC_DIR_SERV	=	$(DIR_SERV)src/
OBJ_DIR_SERV	=	$(DIR_SERV)obj/
DIR_CLIENT		=	client_file/
SRC_DIR_CLIENT	=	$(DIR_CLIENT)src/
OBJ_DIR_CLIENT	=	$(DIR_CLIENT)obj/
LIB_DIR			=	libft/

# .c and .o files
SRC_SERV		=	$(wildcard $(SRC_DIR_SERV)*.c)
OBJ_SERV		=	$(patsubst $(SRC_DIR_SERV)%.c,$(OBJ_DIR_SERV)%.o,$(SRC_SERV))
SRC_CLIENT		=	$(wildcard $(SRC_DIR_CLIENT)*.c)
OBJ_CLIENT		=	$(patsubst $(SRC_DIR_CLIENT)%.c,$(OBJ_DIR_CLIENT)%.o,$(SRC_CLIENT))

# .a files
LIBFT	=	$(LIB_DIR)libft.a

# The main rule
all				:	$(SERVER) $(CLIENT)

# The server rule
$(SERVER)			:	$(OBJ_SERV) $(LIBFT)
	@echo "\033[0;33mCompiling server -> ⏳\033[0m"
	$(CC) $(OBJ_SERV) $(LIBFT) -o $@
	@echo "\033[0;32mServer successfuly compiled -> ✅\033[0m\n"

# The client rule
$(CLIENT)			:	$(OBJ_CLIENT) $(LIBFT)
	@echo "\033[0;33mCompiling client -> ⏳\033[0m"
	$(CC) $(OBJ_CLIENT) $(LIBFT) -o $@
	@echo "\033[0;32mClient successfuly compiled -> ✅\033[0m\n"

# The libft rule
$(LIBFT)		:	$(LIB_DIR)
	@echo "\033[0;33mCompiling my libft -> ⏳\033[0m"
	@make all -sC $<
	@echo "\033[0;32mLibft successfuly compiled -> ✅\033[0m\n"

# Compile .c to .o files for server
$(OBJ_DIR_SERV)%.o	:	$(SRC_DIR_SERV)%.c | $(OBJ_DIR_SERV)
	@echo "\033[0;33mCompiling project src -> ⏳\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mSrc's project successfuly compiled -> ✅\033[0m\n"

# Compile .c to .o files for client
$(OBJ_DIR_CLIENT)%.o	:	$(SRC_DIR_CLIENT)%.c | $(OBJ_DIR_CLIENT)
	@echo "\033[0;33mCompiling project src -> ⏳\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mSrc's project successfuly compiled -> ✅\033[0m\n"

# Create the obj server directory
$(OBJ_DIR_SERV)		:
	@mkdir -p $@

# Create the obj client directory
$(OBJ_DIR_CLIENT)		:
	@mkdir -p $@

# Clean, fclean and re rules
clean			:
	@echo "\033[0;31mCleaning obj files -> 🗑️\033[0m"
	@rm -rf $(OBJ_DIR_SERV)
	@rm -rf $(OBJ_DIR_CLIENT)
	@echo "\033[0;32mDone -> ✅\033[0m\n"

fclean			:	clean
	@echo "\033[0;31mCleaning program -> 🗑️\033[0m"
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@make fclean -sC $(LIB_DIR)
	@echo "\033[0;32mDone -> ✅\033[0m\n"

re				:	fclean all

