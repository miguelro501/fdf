# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:22:05 by miguelro          #+#    #+#              #
#    Updated: 2023/02/23 15:37:36 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_PRINTF = ./Printf/libftprintf.a
FT_PRINTF_PATH = ./Printf

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRC_NAME = ft_isalnum.c ft_isprint.c ft_strlcat.c ft_memchr.c\
ft_atoi.c ft_isalpha.c ft_strrchr.c ft_memcmp.c ft_putendl_fd.c\
ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_putnbr_fd.c\
ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c ft_split.c\
ft_memmove.c ft_strlen.c ft_strncmp.c ft_calloc.c ft_itoa.c\
ft_toupper.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
ft_substr.c ft_strjoin.c ft_strtrim.c\
ft_lstnew.c ft_lstadd_front.c ft_lstclear.c\
ft_lstsize.c ft_lstlast.c ft_lstiter.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c\
get_next_line.c get_next_line_utils.c \

$(VERBOSE).SILENT:

SRC_PATH = ./sources

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

INCLUDES	= -I ../headers/


DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

all: $(NAME)

$(NAME): $(OBJS)
	@make  -s -C $(FT_PRINTF_PATH)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
				@make clean  -s -C $(FT_PRINTF_PATH)
				@rm -rf $(OBJ_PATH)
				@echo "$(YELLOW)$(NAME) files are removed$(DEFAULT)"

fclean:			clean
				@rm -rf objects
				@make fclean  -s -C $(FT_PRINTF_PATH)
				@rm -f $(NAME)
				@echo "$(RED)$(NAME) is deleted$(DEFAULT)"

re:				fclean all
