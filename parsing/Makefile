# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 01:18:51 by fstitou           #+#    #+#              #
#    Updated: 2022/11/02 18:59:12 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror
SANITIZE = -g3 -fsanitize=address
		
SRC = *.c GNL/*.c tools/*.c
MLX = -lmlx -framework OpenGL -framework AppKit


OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME):
	
	@gcc  $(CFLAGS) -g $(SRC) -o $(NAME)
	@echo "👍👍👍"


clean :
 
	@rm -f $(OBJ)
	@echo "🚮🚮🚮"

fclean : clean
	@rm -f $(NAME)
	@echo "🗑️ 🗑️ 🗑️"

re : fclean all