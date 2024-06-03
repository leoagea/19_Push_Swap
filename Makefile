# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagea <lagea@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 01:08:23 by lagea             #+#    #+#              #
#    Updated: 2024/06/03 13:03:48 by lagea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME		= push_swap
BONUS 		= checker
	
SRC_DIR		= src/
BONUS_DIR	= bonus/
OBJ_DIR		= obj/
OBJB_DIR	= obj_bonus/
INC_DIR		= inc/

SRC 		= src/main.c src/algo.c src/check_error.c src/cost.c src/exit.c src/extremum.c \
			src/init_stack.c src/move.c src/parse_arg.c src/reverse_rotate.c src/rotate.c src/sort.c
SRCB 		= bonus/main_bonus.c bonus/checker_bonus.c bonus/move_bonus.c src/check_error.c src/exit.c \
 			src/init_stack.c src/parse_arg.c bonus/reverse_rotate_bonus.c bonus/rotate_bonus.c
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJB		= $(SRCB:$(BONUS_DIR)%.c=$(OBJB_DIR)%.o)

LIBFT 		= lib/libft.a
LIBFT_PATH 	= libft/

CC			= gcc
RM			= rm -f
C_FLAGS		= -Wall -Wextra -Werror
INCS 		= -I$(INC_DIR) -I.

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_push_swap
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling Push Swap... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

TOTAL_FILES_BONUS 	:= $(words $(SRCB))
CURRENT_FILE_BONUS 	:= 0

define progress_bar_checker
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE_BONUS) + 1))))
    @printf "\r$(YELLOW)Compiling Push Swap... [%-$(TOTAL_FILES_BONUS)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE_BONUS)); do printf "#"; done) $(CURRENT_FILE_BONUS) $(TOTAL_FILES_BONUS)
	@if [ $(CURRENT_FILE_BONUS) -eq $(TOTAL_FILES_BONUS) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) $(INCS) -g -c $< -o $@
	$(call progress_bar_push_swap)

$(OBJB_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(OBJB_DIR)
	@$(CC) $(C_FLAGS) $(INCS) -g -c $< -o $@
	$(call progress_bar_checker)
	
all: $(LIBFT) $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJ) -Llib/ -lft -o $(NAME)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

$(BONUS):$(LIBFT) $(OBJB)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJB) -Llib/ -lft -o $(BONUS)
	$(call progress_bar_checker)
	@echo "$(BLUE)Executable $(BONUS) created!$(NC)"
	
$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(NC)"
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@echo "$(ORANGE)Cleaning objects for Libft...$(NC)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)Cleaned objects Libft!$(NC)"
	@echo "$(ORANGE)Cleaning objects for Push Swap...$(NC)"
	@$(RM) $(OBJ_DIR)*.o
	@echo "$(GREEN)Cleaned Push Swap objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for Libft...$(NC)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned Libft!$(NC)"
	@echo "$(ORANGE)Fully cleaning library for Push Swap...$(NC)"
	@$(RM) $(NAME) $(BONUS)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned Push Swap!$(NC)"

re: fclean all

.PHONY: all clean fclean re
