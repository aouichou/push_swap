# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:34:07 by aouichou          #+#    #+#              #
#    Updated: 2022/10/05 17:35:03 by aouichou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

SRC_D		= srcs/
OBJ_D		= objs/
BONUS_OBJ_D	= bonus_objs/
INC_D		= includes/
LIBFT_D		= libft/

SRC			= main.c	\
			args_lists_ops.c	\
			args_lists.c		\
			big_sort.c			\
			calculate.c			\
			free.c				\
			indexing.c			\
			list_max_min.c		\
			move.c				\
			moves_lists.c		\
			operations.c		\
			parsing.c			\
			position.c			\
			print.c				\
			short_sort.c		\
			tools.c				\

BONUS_SRC	= checker.c			\
			args_lists_ops.c	\
			args_lists.c		\
			free.c				\
			moves_lists.c		\
			operations.c		\
			parsing.c			\
			tools.c				\

OBJ			= $(addprefix $(OBJ_D), $(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(BONUS_OBJ_D), $(BONUS_SRC:.c=.o))
FLAGS		= -g -Wall -Werror -Wextra
LIB			= -L libft -lft
INCS		= -I $(INC_D)

all: $(LIBFT_D) $(OBJ_D) $(NAME)

$(OBJ_D):
	@mkdir -p $@

$(NAME): $(OBJ)
	@make -C $(LIBFT_D)
	gcc -o $@ $^ $(LIB)

$(OBJ_D)%.o: $(SRC_D)%.c
	gcc $(FLAGS) -o $@ -c $< $(INCS)

bonus: $(LIBFT_D) $(BONUS_OBJ_D) $(BONUS_NAME)

$(BONUS_OBJ_D):
	@mkdir -p $@

$(BONUS_NAME): $(BONUS_OBJ)
	@make -C $(LIBFT_D)
	gcc -o $@ $^ $(LIB)

$(BONUS_OBJ_D)%.o: $(SRC_D)%.c
	gcc $(FLAGS) -o $@ -c $< $(INCS)

clean:
	@make -C $(LIBFT_D) clean
	rm -rf $(OBJ_D)
	rm -rf $(BONUS_OBJ_D)

fclean: clean
	@make -C $(LIBFT_D) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: clean fclean re all bonus