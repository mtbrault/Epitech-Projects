##
## Makefile for  in /home/b00bix/delivery/CPool_rush3
## 
## Made by Matthieu BRAULT
## Login   <b00bix@epitech.net>
## 
## Started on  Sun Oct 30 04:31:30 2016 Matthieu BRAULT
## Last update Thu Mar 16 18:16:57 2017 Matthieu BRAULT
##

CC	= gcc

RM	= rm -f

SRC	= calculate.c \
	  main.c \
	  my_put_pixel.c \
	  clear_window.c \
	  my_light.c

NAME	= raytracer1

CFLAGS	+= -I./
CFLAGS	+= -Wall -Wextra

LDFLAGS = -L./src -lsrc

OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./src
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS) -lc_graph_prog -lm

clean:
	make clean -C ./src
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ./src
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
