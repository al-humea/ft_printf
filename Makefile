# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 16:19:34 by al-humea          #+#    #+#              #
#    Updated: 2021/01/29 18:48:45 by al-humea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	srcs/ft_printf.c\
		srcs/handlers.c\
		srcs/flags.c\
		srcs/tostr.c

INCLUDES = -I./includes/

CC = clang

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(INCLUDES) $(NAME) $(SRC)

clean:

fclean: clean

re : fclean all

.PHONY: all clean fclean re
