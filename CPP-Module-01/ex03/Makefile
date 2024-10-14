# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 09:43:37 by ebmarque          #+#    #+#              #
#    Updated: 2024/03/29 19:41:27 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Gun

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = src/main.cpp includes/HumanA.cpp includes/HumanB.cpp includes/Weapon.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
