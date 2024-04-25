# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 01:03:14 by gde-alme          #+#    #+#              #
#    Updated: 2023/05/29 15:53:56 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
NAME	=	btc
# ============================================================================ #

# ============================================================================ #
SRCS_DIR	=	./src/
SRCS		=	BitcoinExchange.cpp
SRCS		+=	main.cpp
# ============================================================================ #

# ============================================================================ #
OBJS_DIR	=	obj/
OBJ		=	$(SRCS:%.cpp=%.o)
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJ))
# ============================================================================ #

# ============================================================================ #
CXX		=	c++
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -std=c++98
RM		=	rm -rf
# ============================================================================ #

# ============================================================================ #

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
	$(RM) output_ex

re: fclean all

test: fclean getData
	@echo "\n\t\033[32mDownloading input_ex from github\033[0m\n"
	@curl -LJO https://raw.githubusercontent.com/gde-alme/public/main/CPP_09/input_ex.txt
	@echo "\n\t\033[32mCompiling without VERBOSE\033[0m\n"
	c++ -D VERBOSE=false src/*.cpp -o $(NAME)
	@echo "\n\t\033[32mExecuting with given example to file output_ex\033[0m\n"
	@./$(NAME) input_ex.txt | tee output_ex
	@echo "\n\t\033[32mTest run terminated\033[0m\n"
	@echo "\n\t\033[32mRemoving input_ex\033[0m\n"
	rm input_ex.txt
	@echo "\n\t\033[32mRemoving data.csv\033[0m\n"
	rm data.csv
	@echo "\n\t\033[32mRemoving executable and obj files\033[0m\n"
	@make fclean


getData:
	@echo "\n\t\033[32mDownloading csv from intra\033[0m\n"
	@curl -LJO https://cdn.intra.42.fr/document/document/15277/cpp_09.tgz
	@echo "\n\t\033[32mExtracting folder\033[0m\n"
	@tar -xf cpp_09.tgz
	@mv cpp_09/data.csv ./
	@rm -rf cpp_09/ cpp_09.tgz
	@echo "\n\t\033[32mdata.csv cloned\033[0m\n"

# ================================================= #

.PHONY: all clean fclean re
