# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 12:50:35 by agutierr          #+#    #+#              #
#    Updated: 2020/02/21 12:22:52 by agutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
SRCS = ft_printf.c ft_printf_decimal.c ft_printf_strings.c ft_printf_char.c\
		ft_printf_hex.c\
		ft_printf_utils.c ft_printf_utils2.c\

OBJS = $(SRCS:.c=.o)

INCLUDES = ./

all:$(NAME)

$(NAME):$(SRCS) ft_printf.h
		gcc -Wall -Werror -Wextra -I$(INCLUDES) -c $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

compile:
		gcc -g $(SRCS) main.c

clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:			fclean all
