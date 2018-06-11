# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:48 by jwolf             #+#    #+#              #
#    Updated: 2018/06/08 13:02:42 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILE = maps/42.fdf

CFLAGS += -Wextra -Wall -I./includes/

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

C = gcc

SRC = srcs/

SOURCES = $(SRC)main.c $(SRC)map.c $(SRC)load_file.c $(SRC)draw_map.c \
		 $(SRC)key_handler.c $(SRC)points.c $(SRC)build.c \
		 $(SRC)window_control.c $(SRC)rotation.c

OBJECTS = $(SOURCES:.c=.o)

%.o:		%.c
	@echo "\033[1;35;m[Compiling $<] \t\033[0m: " | tr -d '\n'
	$(C) $(CFLAGS) -c $<
	mv *.o $(SRC)

$(NAME): $(OBJECTS)
	@echo "\033[1;34;m[Making... Pizza]\033[0m"
	cd libft/ && make
	$(C) $(CFLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

all: $(NAME)

clean:
	@echo "\033[1;33;m[Cleaning]\033[0m"
	make -C libft clean
	rm -rf $(OBJECTS)

fclean: clean
	@echo "\033[1;32;m[Force Cleaning]\033[0m"
	make -C libft fclean
	rm -rf $(NAME)

re: fclean clean all
	@echo "\033[1;31;m[Recompiled]\033[0m"

run: re
	make clean
	./$(NAME) $(FILE)

.PHONY: fclean clean all re
