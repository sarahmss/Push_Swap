# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2021/11/02 14:19:09 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= libft.a

LIBFT_PATH		= ./libraries/libft/
SRC_PATH		= ./source/
INCLUDES_PATH	= ./includes/
OBJS_PATH		= ./objects/

SRCS_FILES =	main.c				\
				ut_create_stack.c	\
				ut_lstdoubly.c		\
				ut_init.c			\
				ut_searching.c		\
				op_swap.c			\
				op_push.c			\
				op_rotate.c			\
				op_run.c			\
				op_reverse_rotate.c	\
				st_big_stack.c		\
				st_quick_sort.c		\
				st_big_aux.c		\
				st_small_stack.c	\
				op_optimize.c

SRCS_B_FILES = 	ch_checker.c		\
				ut_create_stack.c	\
				ut_lstdoubly.c		\
				ut_init.c			\
				ut_searching.c		\
				op_swap.c			\
				op_push.c			\
				op_rotate.c			\
				op_run.c			\
				op_reverse_rotate.c	\
				op_optimize.c		\
				st_quick_sort.c

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))
SRCS_B = $(addprefix $(SRC_PATH), $(SRCS_B_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

OBJS_B_FILES = $(patsubst %.c, %.o, $(SRCS_B_FILES))
OBJS_B = $(addprefix $(OBJS_PATH), $(OBJS_B_FILES))

HEADER_FILES	=	push_swap.h	\
					structs.h
HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall -Wextra -g
LIBRARIES	= -L$(LIBFT_PATH) -lft
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(FLAGS) $(LIBRARIES) $(INCLUDES)  -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.c $(HEADERS)
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
			@echo making libft...
			@echo --------------------------
			@make bonus -sC $(LIBFT_PATH)
			@echo done!
			@echo --------------------------

bonus:	$(OBJS_B) $(LIBFT)
			$(CC) $(OBJS_B) $(FLAGS) $(LIBRARIES) $(INCLUDES) -o checker

clean:
			@make -sC $(LIBFT_PATH) fclean
			@make -sC $(LIBFT_PATH) clean
			@rm -f $(OBJS)
			@echo cleaned!
fclean:		clean
			@rm -f $(NAME)
			@rm -f checker
re: fclean all

.PHONY: all clean fclean re
