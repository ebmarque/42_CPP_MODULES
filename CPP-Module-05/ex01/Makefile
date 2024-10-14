# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 16:12:56 by ebmarque          #+#    #+#              #
#    Updated: 2024/06/09 20:06:25 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC_DIR = sources
SRCS = $(addprefix $(SRC_DIR)/, main.cpp Bureaucrat.cpp Form.cpp)
OBJS = $(addprefix OBJS/, $(notdir $(SRCS:.cpp=.o)))

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@echo "$(GREEN)Linking object files...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)$(NAME) successfully compiled!$(NC)"

OBJS/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p OBJS
	@printf "\033[K$(GREEN)Compiling $< ...$(NC)\r"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf OBJS

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -fr $(NAME)

re : fclean all

.PHONY: all clean fclean re