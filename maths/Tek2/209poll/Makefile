##
## EPITECH PROJECT, 2018
## 207demography
## File description:
## makefile
##

CXX	= g++

RM	= rm -f

SRC	= src/main.cpp \
	 src/poll.cpp

NAME	= 209poll

CXXFLAGS	= -I./include -Wall -Wextra -Werror -std=c++14

OBJS	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
