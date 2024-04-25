# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 01:03:14 by gde-alme          #+#    #+#              #
#    Updated: 2023/03/27 18:12:38 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================================= #
NAME	=	ex00_polymorphism
# ================================================= #

# ================================================= #
SRCS_DIR	=	./src/
SRCS		=	Animal.cpp
SRCS 		+=	Cat.cpp
SRCS 		+=	Dog.cpp
SRCS 		+=	WrongCat.cpp
SRCS 		+=	WrongAnimal.cpp
SRCS		+=	main.cpp
# ================================================= #

# ================================================= #
OBJS_DIR	=	obj/
OBJ			=	$(SRCS:%.cpp=%.o)
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJ))
# ================================================= #

# ================================================= #
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM			=	rm -rf
# ================================================= #

# ================================================= #

all: $(NAME)

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.cpp
	@mkdir -p obj/
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

test: fclean
	c++ -D VERBOSE=false src/*.cpp -o $(NAME)
	@./$(NAME)

# ================================================= #

.PHONY: all clean fclean re
