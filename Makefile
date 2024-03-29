# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 22:41:47 by rkochhan          #+#    #+#              #
#    Updated: 2022/03/13 09:09:05 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

SRC		= minirt.c \
		minirt_scene.c \
		minirt_display.c \
		minirt_mlx_hook_functions.c \
		minirt_raytracing.c \
		minirt_raytracing_collision.c \
		minirt_raytracing_light.c \
		minirt_colors.c \
		minirt_mlx_utils.c \
		minirt_parse_elements.c \
		minirt_parse_objects.c \
		minirt_parse_utils.c \
		minirt_error.c \
		get_next_line.c

OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft/

LIBV	= ./libvector/

MLX		= ./mlx-linux

CC		= clang

CFLAGS	= -Wall -Werror -Wextra

INCLUDE	= -I./includes/ -I$(MLX) -I$(LIBFT)

LIBS	= -L$(LIBFT) -L$(LIBV) -L$(MLX) -lft -lvector -lm -lXext -lX11 -lmlx

$(NAME): $(OBJ)
	@ make -s -C $(LIBFT)
	@ make -s -C $(LIBV)
	@ $(CC) $(CFLAGS) -O3 $(OBJ) $(INCLUDE) $(LIBS) -o $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -O3 $(INCLUDE) -c $< -o $(<:.c=.o)

bonus: $(OBJ)
	@ $(CC) $(CFLAGS) -O3 -D MINIRT_BONUS=1 $(INCLUDE) -c $(SRC)
	@ make -s -C $(LIBFT)
	@ make -s -C $(LIBV)
	@ $(CC) $(CFLAGS) -O3 $(OBJ) $(INCLUDE) $(LIBS) -o $(NAME)
	@ echo "Made $(value NAME) with bonus"

clean:
	@ make -s clean -C $(LIBFT)
	@ make -s clean -C $(LIBV)
	@ rm -rf $(OBJ)

fclean: clean
	@ make -s fclean -C $(LIBFT)
	@ make -s fclean -C $(LIBV)
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
