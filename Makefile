# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 21:03:55 by fbenneto          #+#    #+#              #
#    Updated: 2018/02/22 22:12:07 by fbenneto         ###   ########.fr        #
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

SRC_PARSER_DIR =\
	parser/
SRC_PARSER_NAME =\
	ft_parse_tree.c\
	ft_parse_tree_2.c\
	ft_parser.c\
	print_tree.c\
	
SRC_PARSER = $(addprefix $(SRC_PARSER_DIR), $(SRC8PARSER8NAME))

SRC_LEXER_DIR =\
	lexer/
SRC_LEXER_NAME =\
	ft_lexer.c\
	ft_clean_lexem.c\
	ft_print_lexem.c\
	ft_tf_opt_lexem.c\
	
SRC_LEXER = $(addprefix $(SRC_LEXER_DIR), $(SRC_LEXER_NAME))
	
SRC_LIST_DIR =\
	list/
SRC_LIST_NAME =\
	ft_t_token.c\
	ft_t_tree.c\

SRC_LIST = $(addprefix $(SRC_LIST_DIR), $(SRC_LIST_NAME))

SRC_DIR =\
	./srcs/
SRC_NAME=\
	$(SRC_LEXER)\
	$(SRC_LIST)\
	$(SRC_PARSER)\
	main.c\
	ft_read_input.c\
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

$(NAME) : $(OBJ_DIR) $(OBJ_DIR)$(SRC_LEXER_DIR) $(OBJ_DIR)$(SRC_LIST_DIR) $(OBJ_DIR)$(SRC_PARSER_DIR) $(OBJ)
	@printf "[calculator: $@]\n\tdoing compiling $(BOLD)$(CYAN)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@printf ' '$(OK)'\n'

$(OBJ_DIR)$(SRC_LEXER_DIR):
	@printf "[calculator :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)'\n'

$(OBJ_DIR)$(SRC_LIST_DIR):
	@printf "[calculator :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)'\n'

$(OBJ_DIR)$(SRC_PARSER_DIR):
	@printf "[calculator :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)'\n'

$(OBJ_DIR) :
	@printf "[calculator :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
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
