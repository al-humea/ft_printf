# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 16:19:34 by al-humea          #+#    #+#              #
#    Updated: 2021/03/19 09:10:57 by al-humea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	./ft_printf.c\
		srcs/handling.c\
		srcs/flags.c\
		srcs/tostr.c\
		srcs/length.c\
		libft/ft_atoi.c\
		libft/ft_atolu.c\
		libft/ft_itoa.c\
		libft/ft_utoa.c\
		libft/ft_lutoa.c\
		libft/ft_lutox.c\
		libft/ft_lutocx.c\
		libft/ft_fillwith.c\
		libft/ft_nbrlen.c\
		libft/ft_strdup.c\
		libft/ft_chardup.c\
		libft/ft_strsrc.c\
		libft/ft_strlen.c\
		libft/ft_hexalen.c\
		libft/ft_strlcpy.c\
		libft/ft_memset.c\
		libft/ft_strjoin.c\
		libft/ft_putstr_fd.c\
		libft/ft_putstrl_fd.c\
		libft/ft_putchar_fd.c\
		libft/ft_spamc.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	./includes/ft_printf.h

RM	=	rm -f

FLAGS	=	-Wall -Wextra -Werror -g

.c.o:
	clang $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar -rcs libftprintf.a $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re