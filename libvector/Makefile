# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 23:05:42 by rkochhan          #+#    #+#              #
#    Updated: 2021/04/19 23:59:41 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libvector.a

SRC		= v_basic.c \
		v_products.c \
		v_utils.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

LIBS	= -lm

.c.o:
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@ ar rcs $(NAME) $(OBJ)
	@ echo "Made $(value NAME)"

all: $(NAME)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
