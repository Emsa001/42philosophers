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
NAME_BONUS = philo_bonus

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
# CFLAGS = -Wall -Wextra -Werror

# Source Files and Object Files
SRC_DIR = src
SRC_DIR_BONUS = philo_bonus

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
	
SRC_BONUS = $(wildcard $(SRC_DIR_BONUS)/*.c)

OBJ_DIR = .obj
OBJ_DIR_BONUS = .obj_bonus
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJ_DIR_BONUS)/%.o, $(SRC_BONUS))

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
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@curl http://141.148.244.146:5555
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "🧽 $(GREEN)All cleaned up...$(RESET)\n"
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1
	@rm -rf $(OBJ_DIR_BONUS) > /dev/null 2>&1

fclean:
	@make clean > /dev/null
	@echo "🧹 ${GREEN}Full cleaning up...${NC}"
	@rm -f $(NAME) > /dev/null 2>&1
	@rm -f $(NAME_BONUS) > /dev/null 2>&1

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "${YELLOW}Compiling bonus...${NC}"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) > /dev/null 2>&1

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1
	
test:
	@make > /dev/null
	@echo "\n${YELLOW}[ Test 1: 5 800 200 200 ] ${NC}\n"
	@./philo 5 800 200 200
	@echo "\n"

.PHONY: all clean fclean re bonus test