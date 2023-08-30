##
## Makefile for Makefile in /home/kiwiv2/epitech/LIBS/lib_printf
## 
## Made by alexandre
## Login   <alexandre.caila@epitech.eu>
## 
## Started on  Tue Feb  7 15:06:44 2017 alexandre
## Last update Tue Feb  7 15:38:30 2017 alexandre
##

ARRC	=	ar rc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra -Werror -I./include/

NAME	=	libprtf.a

SRCS	=	my_printf.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_strlen.c

OBJS	=	$(SRCS:.c=.o)

RANLIB	=	ranlib

all: $(NAME)

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
