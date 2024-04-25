# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 01:03:14 by gde-alme          #+#    #+#              #
#    Updated: 2023/03/20 12:59:20 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================================= #
NAME	=	Now_its_weird
# ================================================= #

# ================================================= #
SRCS_DIR	=	./
SRCS		=	ClapTrap.cpp 
SRCS		+=	ScavTrap.cpp 
SRCS		+=	FragTrap.cpp
SRCS 		+=	DiamondTrap.cpp
SRCS		+=	main.cpp
# ================================================= #

# ================================================= #
INC			=	ClapTrap.hpp
INC			+=	ScavTrap.hpp
INC			+=	FragTrap.hpp
INC			+=	DiamondTrap.hpp
# ================================================= #

# ================================================= #
OBJS_DIR	=	obj/
OBJ			=	$(SRCS:%.cpp=%.o)
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJ))
# ================================================= #

# ================================================= #
CC			=	@g++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	@rm -rf
# ================================================= #

# ================================================= #
$(OBJS_DIR)%.o :	$(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "\033[0;32mCompiling $<\033[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(INC) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@echo "\033[0;32mCleaning: $(OBJS_DIR)\033[0m"
	$(RM) $(OBJS_DIR)
	
fclean: clean
	@echo "\033[0;32mCleaning: $(NAME)\033[0m"
	$(RM) $(NAME)

re: fclean all

test: fclean
	@g++ -D VERBOSE=false *.hpp *.cpp -o $(NAME)
	@./$(NAME)
# ================================================= #

.PHONY: all clean fclean re
