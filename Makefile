# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozon <gozon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 08:35:14 by gozon             #+#    #+#              #
#    Updated: 2024/09/11 10:47:38 by gozon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
SRC = srcs/main.c
OBJ_DIR = objects
SRC_DIR = srcs
MLX= minilibx-linux/libmlx_Linux.a
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Symboles Unicode
CHECK_MARK = ✔

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(OBJ) -LLibft -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib \
	-lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(NAME) a été créé avec succès ($(CHECK_MARK))"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -ILibft -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIBFT):
	@make -C Libft --silent --no-print-directory
	@echo "Compilation de la Libft ($(CHECK_MARK))"

$(MLX):
	@make -C minilibx-linux --silent --no-print-directory
	@echo "Compilation de la minilibX ($(CHECK_MARK))"

clean:
	$(ECHO)make clean -C Libft --silent --no-print-directory
	$(ECHO)rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "Nettoyage réussi ($(COMP_SUCCESS))"

fclean: clean
	$(ECHO)rm -f $(NAME)
	$(ECHO)rm -f Libft/libft.a
	@echo "Nettoyage complet réussi ($(COMP_SUCCESS))"

re: fclean all

.PHONY: all clean fclean re bonus
