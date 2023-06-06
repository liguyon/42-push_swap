# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:38:40 by liguyon           #+#    #+#              #
#    Updated: 2023/06/06 14:44:19by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		:= push_swap

# Includes
INC_DIR		:= include

# Sources
SRC_DIR		:= src

SRC			:= main.c \
				stack/stack.c \
				stack/utils.c \
				stack2/stack2.c \
				stack2/swap.c \
				stack2/push.c \
				stack2/rotate.c \
				parse.c \

SRC_TEST	:= $(filter-out main.c, $(SRC)) \
				test/test_stack2.c

# Objects
OBJ_DIR		:= .build

OBJ			:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_TEST	:= $(addprefix $(OBJ_DIR)/, $(SRC_TEST:.c=.o))

# Libraries
LIB_DIR		:= lib

LIBFT_DIR	:= $(LIB_DIR)/42-libft

LIBFT		:= libft.a

# Compiler
CC			:= cc

CFLAGS		:= -Wall -Wextra -Werror -g3 -I$(INC_DIR) -I$(LIBFT_DIR)/include #-fsanitize=address

CLFLAGS		:= -L$(LIBFT_DIR) -lft

# Logging
SUCCESS_COLOR	= \033[0;32m
ERROR_COLOR		= \033[0;31m
RESET_COLOR		= \033[0m
COMPILE_MSG		= "Compiling target: "
SUCCESS_MSG		= "Compilation successful: "

# Targets
$(NAME):	$(OBJ) $(LIBFT)
		@echo "$(COMPILE_MSG)$(NAME)"
		@$(CC) $(CFLAGS) $(value OBJ) -o $(NAME) $(CLFLAGS)
		@echo "$(SUCCESS_COLOR)$(SUCCESS_MSG)$(NAME)$(RESET_COLOR)"

$(LIBFT):
		@echo "$(COMPILE_MSG)$@"
		@$(MAKE) -sC $(LIBFT_DIR) all
		@echo "$(SUCCESS_COLOR)$(SUCCESS_MSG)$@$(RESET_COLOR)"

all:		$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -o $@ -c $<

clean:
		@echo "Cleaning up..."
		@rm -rf $(OBJ_DIR)
		@$(MAKE) -sC $(LIBFT_DIR) clean
		@echo "$(SUCCESS_COLOR)Done$(RESET_COLOR)"

fclean:	clean
		@rm -f $(NAME)
		@$(MAKE) -sC $(LIBFT_DIR) fclean

re: 		fclean all

test:	$(OBJ_TEST) $(LIB_DIR)
		@echo "$(COMPILE_MSG)$(NAME)"
		@$(CC) $(CFLAGS) $(value OBJ_TEST) -o $@ $(CLFLAGS)
		@echo "$(SUCCESS_COLOR)$(SUCCESS_MSG)$(NAME)$(RESET_COLOR)"

.PHONY: 	all clean fclean re
