#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 15:52:41 by yli               #+#    #+#              #
#    Updated: 2017/05/23 16:42:27 by yli              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src
FILENAMES = $(SRC)/ft_printf.c \
	$(SRC)/ft_conv_str.c \
	$(SRC)/ft_handle_str.c \
	$(SRC)/ft_pad_str.c \
	$(SRC)/parsing.c \
	$(SRC)/printing.c \

OBJECTS	= $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(SRC)/libft/libft.a
	cd $(SRC)/libft && make && make clean
	$(CC) -c -o $(NAME) $(OBJECTS) ./src/libft/libft.a

%.o: %.c
		$(CC) $(CFLAGS) -c -I . -I ./libft -o $@ $<

clean:
		/bin/rm -f $(OBEJCTS)

fclean: clean
		cd libft && make fclean
		cd ../
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
