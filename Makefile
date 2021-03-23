# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 22:41:47 by rkochhan          #+#    #+#              #
#    Updated: 2021/03/23 14:33:03 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

SRC		= minirt.c

OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft

MLX		= ./mlx-linux

CC		= clang

CFLAGS	= -Wall -Werror -Wextra -O3

INCLUDE	= -I./includes/

LINK	= -L$(LIBFT) -L$(MLX)

LIBS	= -lXext -lX11 -lmlx

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ $(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LINK) -o $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
