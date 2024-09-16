# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozon <gozon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 08:35:14 by gozon             #+#    #+#              #
#    Updated: 2024/09/16 16:04:01 by gozon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
SRC = srcs/calculate_julia_mb.c srcs/complex_arithmetic.c srcs/color_image.c \
	srcs/window.c
OBJ_DIR = objects
SRC_DIR = srcs
MLX= minilibx-linux/libmlx_Linux.a
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Symboles Unicode
CHECK_MARK = ✔

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(OBJ) -LLibft -lft -Lminilibx-linux -lmlx_Linux \
	-lXext -lX11 -lm -o $(NAME)
	@echo "$(NAME) a été créé avec succès ($(CHECK_MARK))"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Iminilibx-linux -ILibft -Iincludes -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIBFT):
	@make -C Libft --silent --no-print-directory
	@echo "Compilation de la Libft ($(CHECK_MARK))"

$(MLX):
	@make -C minilibx-linux --silent --no-print-directory
	@echo "Compilation de la minilibX ($(CHECK_MARK))"

clean:
	@make clean -C Libft --silent --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage réussi ($(CHECK_MARK))"

fclean:
	@rm -f $(NAME)
	@make fclean -C Libft --silent --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage complet réussi ($(CHECK_MARK))"

re: fclean all

.PHONY: all clean fclean re bonus
