##
## EPITECH PROJECT, 2018
## bollinger
## File description:
## makefile
##

CXX	=	g++

RM	=	rm -f

SRC	=	main.cpp		\
		calc.cpp

NAME	=	202unsold

CXXFLAGS	=	-I./include -Wall -Wextra -Werror -lm

OBJS	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
