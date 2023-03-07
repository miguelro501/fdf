# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 17:00:30 by marvin            #+#    #+#              #
#    Updated: 2023/03/06 15:38:53 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Imlx -g 

LIBFT = ./Libft/libft.a
LIBFT_PATH = ./Libft

PRINTF = ./Libft/Printf/libftprintf.a

INCLUDES = -I ./headers/

SRC_PATH = ./sources

OBJ_PATH = ./objects

SRC_NAME = 	main.c\
			plot.c\
			utils.c\
			global_struct.c\
			geometry.c\
			keys.c\
			generate_map.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -Imlx_linux

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME) : $(OBJS)
	@make -s -C $(LIBFT_PATH)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(MAKE) -s -C mlx_linux
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled $(DEFAULT)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(MLX_LIB)
	@mkdir -p objects
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) $(CFLAGS) $(objects) -c $(^) -o $(@)

clean:
	@make clean -s -C $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)
	@echo "$(YELLOW)$(NAME) files are removed$(DEFAULT)"

fclean:
	@rm -rf objects/
	@make fclean -s -C $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is deleted$(DEFAULT)"


re: fclean all


# CC			= 	cc -Wall -Wextra -Werror  -g # -fsanitize=address
# RM			= 	/bin/rm -f
# NAME		= 	fdf
# INCLUDES	= 	-Iheaders/
# SRCS		=   $(shell find sources/ -name '*.c')
# OBJS		= 	$(SRCS:.c=.o)
# 
# 
# MLX_LIB_DIR = mlx_linux/
# MLX_INCLUDE = -Imlx_linux
# COLOUR_GREEN=\033[7;1;32m
# COLOUR_END=\033[0m
# COLOUR_YELLOW=\033[7;1;33m
# 
# MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
# 
# # ^ primeira dependencia
# # @ nome da regra
# all: $(NAME)
# 
# $(NAME): $(OBJS) 
# 	@$(MAKE) -s -C mlx_linux
# 	@$(CC) $(^) $(MLX_FLAGS) -o $(@)
# 
# %.o: %.c $(MLX_LIB)
# 	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)
# 
# bonus: all
# 
# clean:
# 	@$(RM) $(OBJS)
# 	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"
# 
# fclean: clean
# 	@$(RM) $(NAME)
# 	@echo "\033[0;31mREMOVED cub3D EXECUTABLE\033[0m"
# 
# re: fclean all