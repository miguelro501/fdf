# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:22:05 by miguelro          #+#    #+#              #
#    Updated: 2023/02/23 13:53:57 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

$(VERBOSE).SILENT:

SRC_NAME = ft_check_format.c ft_printf.c \
			ft_put.c ft_putnbrs.c \

SRC_PATH = ./sources

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

INCLUDES	= 	-I ../../headers/

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

$(VERBOSE).SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(YELLOW)$(NAME) files are removed$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is deleted$(DEFAULT)"

re:	fclean all