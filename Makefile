# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 21:03:55 by fbenneto          #+#    #+#              #
#    Updated: 2018/02/18 21:51:27 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME=calculator

############
# COMPILER #
############

CC=clang
CFLAGS=-Wall -Werror -Wextra

##########
# HEADER #
##########

INC_DIR = ./includes/
INC_NAME = \
	calculator.h\
	
INCLUDE = $(addprefix $(INC_DIR), $(INC_NAME))
INC = -I $(INC_DIR)

#######
# SRC #
#######

SRC_DIR =\
	./srcs/
	
SRC_NAME=\
	main.c\
	ft_read_input.c\
	ft_clean_lexem.c\
	ft_tf_opt_lexem.c\
	ft_print_lexem.c\
	ft_lexer.c\
	ft_paser.c\
	ft_iswhat.c\

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

#######
# OBJ #
#######

OBJ_DIR= ./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_NAME))

#########
# MACRO #
#########

NC		= "\\033[0m"
RED		= "\\033[31m"
GREEN	= "\\033[32m"
YELLOW	= "\\033[33m"
BLUE	= "\\033[34m"
MAJENTA	= "\\033[35m"
CYAN	= "\\033[36m"
BOLD	= "\\033[1m"
CHEK	= "✓"
OK		= "$(GREEN)$(CHEK)$(NC)"

#########
# RULES #
#########

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)
	@printf "[calculator: $@]\n\tdoing compiling $(BOLD)$(CYAN)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@printf ' '$(OK)'\n'

$(OBJ_DIR) :
	@printf "[calculator :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $(OBJ_DIR)
	@printf ' '$(OK)'\n'

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	@printf "\tcompile $(BOLD)$(YELLOW)$@$(NC) "
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@printf $(OK)'\n'

clean : $(OBJ_DIR)
	@printf "[calculator: $@]\n\trm all $(BOLD)$(RED) obj file$(NC)"
	@rm -rf $(OBJ_DIR)
	@printf ' '$(OK)'\n'

naelc :
	@printf "[calculator: $@] rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)'\n'

norme : $(SRC) $(INCLUDE)
	@printf "[calculator: $@]\n\tchecking\n"
	@norminette $^

fclean : clean
	@printf "[calculator: $@]\n\trm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)'\n'

proper :
	@make -C ./ all
	@make -C ./ clean

re :
	@make -C ./ fclean
	@make -C ./ all

.PHONY: proper re norme all fclean clean
