# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomek <tomek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 16:09:49 by tomek             #+#    #+#              #
#    Updated: 2024/09/15 23:28:47 by tomek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME			= push_swap

# Directories
LIBFT			= ./libft/libft.a
INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compiler & flags
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -I
RM				= rm -rf

# Source files
COMMANDS_DIR	=	$(SRC_DIR)actions/swap.c \
					$(SRC_DIR)actions/rotate.c \
					$(SRC_DIR)actions/rev_rotate.c \
					$(SRC_DIR)actions/sort_three.c 

PUSH_SWAP_DIR	=	$(SRC_DIR)push_swap/push_swap.c \
					$(SRC_DIR)push_swap/errors.c \
					$(SRC_DIR)push_swap/init.c \
					$(SRC_DIR)push_swap/sanity.c \
					$(SRC_DIR)push_swap/utils.c \
					$(SRC_DIR)push_swap/stack_node.c \
					$(SRC_DIR)push_swap/stack_utils.c

# Concatenate all source files
SRCS 			= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build libft if not already biult

$(LIBFT):
				@make -C ./libft

# Build rules

all:			$(NAME)

# Build the executalble
$(NAME): 		$(OBJ) $(LIBFT)
				@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean object files
clean:
				@$(RM) -r $(OBJ_DIR)
				@make clean -C ./libft

# Clean everything
fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)

# Rebuild everything
re:				fclean all

# Phony targets represent actions not files
.PHONY:			all clean fclean re