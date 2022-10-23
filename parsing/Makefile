# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 01:18:51 by fstitou           #+#    #+#              #
#    Updated: 2022/10/23 12:12:03 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address
		
SRC = *.c GNL/*.c tools/*.c

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