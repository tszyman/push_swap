# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 16:09:49 by tomek             #+#    #+#              #
#    Updated: 2024/09/02 21:50:01 by tszymans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g
LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a
RM			= rm -rf
SRCS		= push_swap.c errors.c init.c init_utils.c sanity.c utils.c stack_node.c #actions.c sort.c
#SRC			= $(addprefix ./src/, $(SRCS))
SRC		= $(SRCS)
OBJ			= $(SRC:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ):	$(SRC)
	@$(CC) $(CFLAGS) -c $^ -I$(LIBFT_DIR)
#	@mv *.o src

clean:
#	@$(RM) src/*.o
	@$(RM) *.o
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean

.PHONY: all clean fclean re
