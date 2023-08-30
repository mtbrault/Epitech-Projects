##
## Makefile for Makefile in /home/kiwiv2/epitech/LIBS
## 
## Made by alexandre
## Login   <alexandre.caila@epitech.eu>
## 
## Started on  Mon Mar  6 09:04:51 2017 alexandre
## Last update Sun May 21 20:25:31 2017 alexandre
##

CC	=	gcc

DB	=	gcc -g3

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -I./include/

LDFLAGS	+=	-L./lib/libprtf.a -lprtf -L./lib/my -lmy

NAME	=	42sh

SRCS	=	src/main.c				\
		src/loop.c				\
		src/my_shrc.c				\
		src/alias/my_alias_create.c		\
		src/alias/replace_alias.c		\
		src/alias/my_alias.c			\
		src/alias/setalias.c			\
		src/alias/unalias.c			\
		src/alias/show_alias.c			\
		src/builtin/exit.c			\
		src/builtin/unsetenv.c			\
		src/builtin/my_cd.c			\
		src/builtin/my_echo.c			\
		src/builtin/env.c			\
	  	src/builtin/change_pwd.c		\
		src/builtin/setenv.c			\
		src/builtin/dump_history.c		\
		src/builtin/manipulate_hist.c		\
		src/exec/exec.c				\
		src/exec/input.c			\
		src/exec/globing.c			\
		src/exec/jobs_control.c			\
		src/exec/my_path.c			\
		src/other/list_to_table.c		\
		src/other/fill.c			\
		src/other/error.c			\
		src/other/my_epurstr.c			\
		src/other/free.c			\
		src/parsing/my_separators.c		\
		src/parsing/create_tab.c		\
		src/parsing/count_cmd.c			\
		src/parsing/new_size_tab.c		\
		src/parsing/remove_cmd.c		\
		src/parsing/replace_exit.c		\
		src/parsing/parth_sep.c			\
		src/parsing/remove_spaces.c		\
		src/parsing/verif_pos_sep.c		\
		src/parsing/my_separators_next.c	\
		src/parsing/check_unmatch.c		\
		src/separators/separate.c		\
		src/separators/pipes.c			\
		src/separators/redir.c			\
		src/separators/semi_colon.c		\
		src/separators/andor.c			\

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/libprtf.a
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

debug: $(OBJS)
	make debug -C ./lib/my
	make -C ./lib/libprtf.a
	$(DB) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C ./lib/libprtf.a
	make clean -C ./lib/my
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	make fclean -C ./lib/libprtf.a
	make fclean -C ./lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
