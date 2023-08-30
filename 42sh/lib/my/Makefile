##
## Makefile for  in /home/b00bix/delivery/Semester2/CProgElem/CPE_2016_matchstick/lib/my
## 
## Made by Matthieu BRAULT
## Login   <b00bix@epitech.net>
## 
## Started on  Tue Feb 14 16:54:38 2017 Matthieu BRAULT
## Last update Sat May 20 13:35:40 2017 Capitaine CASSE
##

CC	=	gcc

DB	=	gcc -g3

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -Werror

SRCS	=	my_strdup.c		\
		str_to_wordtab.c	\
		my_putstr.c		\
		my_strlen.c		\
		my_getnbr.c		\
		get_next_line.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_puterror.c		\
		my_strcat.c		\
		my_arrdup.c		\
		my_tabncmp.c		\
		my_tablen.c		\
		my_tabcat.c		\

NAME	=	libmy.a

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) ..

debug: $(OBJS)
	$(DB) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) ..

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re debug
