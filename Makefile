# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@42studen>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 10:56:47 by wchen             #+#    #+#              #
#    Updated: 2022/11/18 03:10:31 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address -fsanitize=integer -fsanitize=undefined -I $(INCLUDES_DIR)

MAIN			=	./srcs/push_swap/main.c
MAIN_OBJ		=	$(MAIN:.c=.o)

INCLUDES_DIR	=	./includes
INCLUDES		=	$(addprefix $(INCLUDES_DIR),/push_swap.h	\
												/ft_printf.h	\
												)				\
##libft
LIBFT_DIR		=	./libft/
LIBFT			=	$(LIBFT_DIR)libft.a

##ft_printf
PF_DIR		=	./srcs/ft_printf
PF_SRCS		=	$(addprefix $(PF_DIR),/ft_printf.c		\
									/print_char.c		\
									/print_str.c		\
									/print_int.c		\
									/print_unint.c		\
									/print_x.c			\
									/print_bx.c			\
									/print_ptr.c		\
									)
PF_OBJS		= 	$(PF_SRCS:.c=.o)
PRINTF		=	./srcs/ft_printf/libftprintf.a

##push_swap
SW_DIR			=	./srcs/push_swap
SW_SRCS			=	$(addprefix $(SW_DIR),/list_init.c		\
										/err_exit.c			\
										/ft_atoi_exit.c		\
										/merge_sort_list.c	\
										/convert_binary.c	\
										/push_swap.c		\
										/push_swap_method.c	\
										/free_all.c			\
										)
SW_OBJS	=	$(SW_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(MAIN_OBJ) $(SW_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SW_OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(PRINTF): $(LIBFT) $(PF_OBJS)
	cp		libft/libft.a srcs/ft_printf
	mv		srcs/ft_printf/libft.a srcs/ft_printf/libftprintf.a
	ar rcs $(PRINTF) $(PF_OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f ${MAIN_OBJ}
	rm -f ${PF_OBJS}
	rm -f ${SW_OBJS}

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f ${PRINTF}
	rm -f ${NAME}

re: fclean all

