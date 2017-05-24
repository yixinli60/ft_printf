#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 15:52:41 by yli               #+#    #+#              #
#    Updated: 2017/04/06 16:00:42 by yli              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILENAMES = ./src/ft_printf.c \
	./src/ft_conv_str.c \
	./src/ft_handle_str.c \
	./src/ft_pad_str.c \
	./src/parsing.c \
	./src/printing.c \

OBJECTS	= $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) ./src/libft/libft.a

	cd src/libft && make && make clean
	cp ./src/libft/libft.a $@
	ar -rc $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I . -I ./libft -o $@ $<

clean:
		/bin/rm -f ./src/$(OBEJCTS)

fclean: clean
		cd libft && make fclean
		cd ../
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
