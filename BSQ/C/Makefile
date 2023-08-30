##
## Makefile for  in /home/b00bix/delivery/CPool_rush3
## 
## Made by Matthieu BRAULT
## Login   <b00bix@epitech.net>
## 
## Started on  Sun Oct 30 04:31:30 2016 Matthieu BRAULT
## Last update Fri Dec 16 23:57:39 2016 Matthieu BRAULT
##

CC	= gcc

RM	= rm -f

SRC	= error_handling.c \
	  main.c \
	  my_tab.c \
	  algo.c \
	  display_result.c \
	  error.c \
	  special_case.c

NAME	= bsq

OBJS	= $(SRC:.c=.o)

CFLAGS	+= -I./include
CFLAGS	+= -Wall -Wextra

LDFLAGS	= -L./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
