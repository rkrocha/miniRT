# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 22:41:47 by rkochhan          #+#    #+#              #
#    Updated: 2021/04/08 09:47:22 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

SRC		= minirt.c minirt_scene.c minirt_error.c

OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft/

MLX		= ./mlx-linux

CC		= clang

CFLAGS	= -Wall -Werror -Wextra

DEBUG	= -fsanitize=address -g3

INCLUDE	= -I./includes/

LIBS	= -L$(LIBFT) -L$(MLX)

LINK	= -lft -lXext -lX11 -lmlx

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ $(CC) $(CFLAGS) -O3 $(OBJ) $(INCLUDE) $(LIBS) $(LINK) -o $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

debug:
	@ make -s -C $(LIBFT)
	@ $(CC) $(CFLAGS) $(DEBUG) $(SRC) $(INCLUDE) $(LIBS) $(LINK) -o $(NAME)
	@ echo "Made $(value NAME) for debug"

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
