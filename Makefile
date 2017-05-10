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

OBJECTS = ft_printf.o \
	ft_con_str.o \
	parsing.o \
	printing.o 

all: $(NAME)

$(NAME): $(OBJECTS)
ar rc $(NAME) $(OBEJCTS)

clean:
	/bin/rm -f $(OBEJCTS)

fclean: clean
	/bing/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
