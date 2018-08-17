# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmushta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:56:19 by kmushta           #+#    #+#              #
#    Updated: 2018/03/01 16:56:22 by kmushta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

SRC := add.c create_maps.c draw.c errors.c image.c keyboard.c line.c main.c \
	man.c projection.c read_map.c utils.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)inc/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

LIBMLX_FLAGS := -lmlx -framework OpenGL -framework AppKit

CC_FLAGS := -Wall -Wextra -Werror -O2

LINK_FLAGS := $(LIBFT_FLAGS) $(LIBMLX_FLAGS)

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): $(INC_DIR)fdf.h | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
