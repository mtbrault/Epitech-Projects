##
## Makefile for  in /home/b00bix/delivery/Semester2/CProgElem/CPE_2016_matchstick/lib/my
## 
## Made by Matthieu BRAULT
## Login   <b00bix@epitech.net>
## 
## Started on  Tue Feb 14 16:54:38 2017 Matthieu BRAULT
## Last update Tue Feb 28 18:46:01 2017 Matthieu BRAULT
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall

SRCS	= calc_dir_vector.c \
	  sphere.c \
	  cone.c \
	  cylinder.c \
	  rotate.c \
	  translate.c \
	  plane.c \
	  light.c \
	  utils.c

NAME	= libsrc.a

CFLAGS	+= -I./../
CFLAGS	+= -Wall -Wextra

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -c $(SRCS) $(CFLAGS) -lc_graph_prog
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
