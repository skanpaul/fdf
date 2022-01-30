# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:06:13 by ski               #+#    #+#              #
#    Updated: 2022/01/20 14:06:21 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= fdf

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MLXPATH	= minilibx_macos/
MLXFLAG	= -L$(MLXPATH) -lmlx -L. -lft -lm -framework OpenGL -framework AppKit

RM		= rm -f

HD		= $(wildcard *.h)

SRC		= $(wildcard *.c)

OBJ		= $(SRC:.c=.o)

# **************************************************************************** #
all: $(NAME)

$(NAME): $(OBJ) $(HD)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $(NAME)

s: $(OBJ) $(HD)
	$(CC) $(OBJ) $(MLXFLAG) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# **************************************************************************** #
.PHONY: all clean fclean all

# **************************************************************************** #
l: $(OBJ) $(HD)
	$(CC) $(CFLAGS) $(OBJ) $(LNXFLAG) -o $(NAME)

r:
	./$(NAME)