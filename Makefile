# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:48 by jwolf             #+#    #+#              #
#    Updated: 2018/06/06 10:13:33 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS += -Wextra -Werror -Wall -I./includes/

SRC = ./srcs/

SOURCES = $(SRC)main.c
