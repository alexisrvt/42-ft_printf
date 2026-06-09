# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arivet <arivet@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 19:58:37 by arvt              #+#    #+#              #
#    Updated: 2026/06/09 13:52:29 by arivet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        = ft_printf.c \
			  ft_dispatch.c \
			  ft_initform.c \
			  ft_parse.c \
			  ft_printchar.c \
			  ft_printint.c \
			  ft_printpad.c \
			  ft_printstr.c \
			  ft_utils_nbr.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re