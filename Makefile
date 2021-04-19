# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 22:41:47 by rkochhan          #+#    #+#              #
#    Updated: 2021/04/16 13:52:18 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

SRC		= minirt.c \
		minirt_scene.c \
		minirt_parse_elements.c \
		minirt_parse_objects.c \
		minirt_parse_utils.c \
		minirt_debug_elements.c \
		minirt_debug_objects.c \
		minirt_error.c \
		get_next_line.c

OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft/

MLX		= ./mlx-linux

CC		= clang

CFLAGS	= -Wall -Werror -Wextra

DEBUG	= -fsanitize=address -g3 -D MINIRT_DEBUG=1

INCLUDE	= -I./includes/

LIBS	= -L$(LIBFT) -L$(MLX) -lft -lXext -lX11 -lmlx

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ $(CC) $(CFLAGS) -O3 $(OBJ) $(INCLUDE) $(LIBS) -o $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -O3 $(INCLUDE) -c $< -o $(<:.c=.o)

debug:
	@ make -s -C $(LIBFT)
	@ $(CC) $(CFLAGS) $(DEBUG) $(SRC) $(INCLUDE) $(LIBS) -o $(NAME)
	@ echo "Made $(value NAME) for debug"

clean:
	@ make -s clean -C $(LIBFT)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
