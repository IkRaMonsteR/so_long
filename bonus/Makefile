# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 14:44:05 by irkalini          #+#    #+#              #
#    Updated: 2025/01/03 01:11:41 by irkalini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long_bonus.c map_parsing_bonus.c map_validity_bonus.c \
	../librairies/get_next_line/get_next_line.c \
	../librairies/get_next_line/get_next_line_utils.c \
	window_bonus.c movements_bonus.c utils_bonus.c

OBJS = ${SRCS:.c=.o}

FT_PRINTF_A = ./../librairies/ft_printf/libftprintf.a
FT_PRINTF_DIR = ./../librairies/ft_printf

LIBFT_A = ./../librairies/libft/libft.a
LIBFT_DIR = ./../librairies/libft

MLX_A = ./../minilibx-linux/libmlx.a
MLX_DIR = ./../minilibx-linux

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L../minilibx-linux -l:libmlx_Linux.a -L/usr/lib -lX11 -lXext -lXrandr -lXrender -lm -lpthread -lbsd

all: $(FT_PRINTF_A) $(LIBFT_A) $(MLX_A) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(FT_PRINTF_A) $(LIBFT_A)

$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(FT_PRINTF_A)
	rm -f $(LIBFT_A)
	rm -f $(MLX_A)

re: fclean all

.PHONY: all clean fclean re
