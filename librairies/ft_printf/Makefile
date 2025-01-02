# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 13:33:14 by irkalini          #+#    #+#              #
#    Updated: 2024/07/15 16:59:11 by irkalini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_print_c.c ft_print_s.c ft_print_di.c ft_print_p.c ft_print_u.c \
	ft_print_x.c ft_printf.c

OBJS = ${SRCS:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
