# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 14:09:18 by ebmarque          #+#    #+#              #
#    Updated: 2024/03/06 14:40:12 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ppa

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = src/ppa.cpp includes/PhoneBook.cpp includes/Contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re