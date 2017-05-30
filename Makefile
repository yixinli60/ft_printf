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
	ft_conv_str.c \
	ft_handle_str.c \
	ft_pad_str.c \
	parsing.c \
	printing.c \

OBJECTS	= $(FILENAMES:.c=.o)

all: $(NAME)

#$(NAME): $(OBJECTS) $(LIBFT)
#	cp $(LIBFT) $@
#	ar -rc $@ $(OBJECTS)

#%.o: %.c
#	$(CC) $(CFLAGS) -c -I . -I ./src/libft -o $@ $<

#$(LIBFT): force
#	$(MAKE) -C $(LIBFT_DIR)

#force:
#	true

#clean:
#	/bin/rm -f $(OBJECTS)

#fclean: clean
#		cd ./src/libft && make fclean
#		cd ../
#		/bin/rm -f $(NAME)


$(NAME): $(OBJECTS) $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a $@
	ar -rc $@ $(OBJECTS)
#	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -c -I . -I $(LIBFT_DIR)/libft -o $@ $<

./src/libft/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	cd $(LIBFT_DIR) && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re ./libft/libft.a
