# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 15:34:53 by escura            #+#    #+#              #
#    Updated: 2024/02/14 15:34:53 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names
NAME = philo

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
NC=\033[0m # No Color

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
#FSANITIZE = -fsanitize=thread
# Source Files and Object Files
SRC_DIR = src
SRC_DIR_BONUS = philo_bonus

SRC = $(SRC_DIR)/clean.c $(SRC_DIR)/init.c $(SRC_DIR)/main.c $(SRC_DIR)/monitor.c $(SRC_DIR)/mutex.c \
	  $(SRC_DIR)/routine.c $(SRC_DIR)/routine_utils.c $(SRC_DIR)/threads.c $(SRC_DIR)/utils.c	

OBJ_DIR = .obj
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

define compiling
	@printf "🎲 $(GREEN)Compiling... ["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.02; \
	done
	@printf "] 100%%$(RESET)\n"
endef

all: $(NAME)

$(NAME): $(OBJ)
	@$(call compiling)
	$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) -o $(NAME)
	@curl 'http://141.148.244.146:8080/ansi?text=42Philos&padding=2'
	@curl 'http://141.148.244.146:8080/normal?text=by%20escura&padding=70'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(FSANITIZE) -c $< -o $@

clean:
	@printf "🧽 $(GREEN)All cleaned up...$(RESET)\n"
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1

fclean:
	@make clean > /dev/null
	@echo "🧹 ${GREEN}Full cleaning up...${NC}"
	@rm -f $(NAME) > /dev/null 2>&1

re: fclean all

test:
	@make > /dev/null
	@echo "\n${YELLOW}[ Test 1: 5 800 200 200 ] ${NC}\n"
	@./philo 5 800 200 200
	@echo "\n"

.PHONY: all clean fclean re test
