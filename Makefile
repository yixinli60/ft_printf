#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 15:52:41 by yli               #+#    #+#              #
#    Updated: 2017/05/27 17:27:23 by yli              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./src/libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = ft_printf.c \
	ft_conv_dioux.c \
	ft_conv_cps.c \
	ft_handle_str.c \
	ft_pad_str.c \
	parsing.c \
	printing.c \
	parse_dioux.c \
	ft_conv_pct.c
	
OBJECTS	= $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $@
	ar -rc $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I . -I ./src/libft -o $@ $<

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

force:
	true

clean:
	/bin/rm -f $(OBJECTS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	cd ./src/libft && make fclean
	cd ../
	/bin/rm -f $(NAME)

re: fclean all
