# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozon <gozon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 08:35:14 by gozon             #+#    #+#              #
#    Updated: 2024/09/25 11:28:14 by gozon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
SRC = srcs/calculate_fractal.c \
	srcs/color_image.c \
	srcs/arithmetic.c \
	srcs/draw_fractal.c \
	srcs/window.c \
	srcs/hooks.c \
	srcs/main.c \
	srcs/parsing.c \
	srcs/parsing_utils.c
SRC_BONUS = srcs_bonus/calculate_fractal_bonus.c \
	srcs_bonus/color_image_bonus.c \
	srcs_bonus/arithmetic_bonus.c \
	srcs_bonus/draw_fractal_bonus.c \
	srcs_bonus/window_bonus.c \
	srcs_bonus/hooks_bonus.c \
	srcs_bonus/main_bonus.c \
	srcs_bonus/parsing_bonus.c \
	srcs_bonus/parsing_double_bonus.c \
	srcs_bonus/parsing_additionals_bonus.c \
	srcs_bonus/transformations_bonus.c
OBJ_DIR = objects
SRC_BONUS_DIR = srcs_bonus
SRC_DIR = srcs
MLX= minilibx-linux/libmlx_Linux.a
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(OBJ_BONUS) -LLibft -lft -Lminilibx-linux -lmlx_Linux \
	-lXext -lX11 -lm -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) a été créé avec succès ($(CHECK_MARK))"

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Iminilibx-linux -ILibft -Iincludes -c $< -o $@

clean:
	@make clean -C Libft --silent --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage réussi ($(CHECK_MARK))"

fclean:
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C Libft --silent --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "Nettoyage complet réussi ($(CHECK_MARK))"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
