# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 11:22:23 by reeer-aa          #+#    #+#              #
#    Updated: 2025/07/31 11:23:16 by reeer-aa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

HEADERS = ./includes/

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
RESET = \033[0m

all: ${NAME}

%.o : %.cpp
	@echo "$(BLUE)Compiling $(CYAN)$< $(RESET)..."
	@${CXX} ${CXXFLAGS} -I ${HEADERS} -c $< -o $@

${NAME}: ${OBJS}
	@echo "$(GREEN)Linking objects into $(CYAN)${NAME}$(RESET)..."
	@${CXX} ${CXXFLAGS} -I ${HEADERS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)Build complete!$(RESET)"

clean :
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f ${OBJS}
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean : clean
	@echo "$(RED)Removing $(CYAN)${NAME}$(RESET)..."
	@rm -f ${NAME}
	@echo "$(GREEN)Full clean complete!$(RESET)"

re : fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re