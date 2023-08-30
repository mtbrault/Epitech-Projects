/*
** 42sh.h for 42sh in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_42sh/include
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon Apr 10 10:43:06 2017 alexandre
** Last update Sun May 21 20:51:37 2017 Matthieu BRAULT
*/

#ifndef MYSH_H_
# define MYSH_H_

/*
** RETURNS
*/
# define SUCCESS	(0)
# define ERROR		(84)
# define FAIL		(-1)

/*
** TOOLS
*/
# define AMB_PIPE	(1)
# define AMB_ARROW	(4)
# define AMB_DARROW	(5)
# define NB_BUILTS	(7)
# define TAB_P		(9)
# define SPACES_T	(-62)
# define RIGHTS		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# define COMMENT	'#'
# define TO_MATCH	"])'"
# define INV_MATCH	"[('"
# define TO_SEPARATE	";|&<>[]()\\!$"
# define SEPARATORS	";|&<>"
# define EXPORT		"export"
# define ALIAS		"alias"
# define UNALIAS	"unalias"
# define EXIT_S		"exit"
# define PWD		"PWD"
# define OLDPWD		"OLDPWD"
# define CD		"cd"
# define SETENV		"setenv"
# define UNSETENV	"unsetenv"
# define ENV		"env"
# define ECHO		"echo"
# define CTR_C		"\b\b  \n"
# define HOME		"HOME"
# define HISTORY	"./.42_history"
# define PATH		"PATH"
# define SET		"set"
# define SET_HIST	"history"
# define SET_SAVEH	"savehist"
# define SET_PROMPT	"prompt"
# define PROMPT		"42sh>"
# define EXIT		"exit\n"
# define SHRC		"./.kekshrc"

/*
** ERROR MESSAGES
*/
# define LINE_ERR	"Line:"
# define CORRUPTED	":Corrupted .kekshrc.\n"
# define UNMATCH	"Unmatched"
# define HISTORY_BADN	"history: Badly formed number.\n"
# define HISTORY_US	"Usage: history [-chrSLMT] [# number of events].\n"
# define HISTORY_TM	"history: Too many arguments.\n"
# define AMBIGUOUS	"Ambiguous input redirect.\n"
# define EVENT_HIST	": Event not found.\n"
# define INVALID	"Invalid null command.\n"
# define MISSING	"Missing name for redirect.\n"
# define CMD_NF		": Command not found.\n"
# define SYNTAX_ERROR	"exit: Expression Syntax.\n"
# define NO_PERMISSION	": Permission denied.\n"
# define NOT_A_DIR	": Not a directory.\n"
# define NO_FILE	": No such file or directory\n"
# define CD_MANY_ARG	"cd: Too many arguments.\n"
# define ALPHA_ONE	"setenv: Variable name must contain"
# define ALPHA_TWO	" alphanumeric characters.\n"
# define ALPHA		ALPHA_ONE ALPHA_TWO
# define MANY_ARG	"setenv: Too many arguments.\n"
# define TOO_FEW	"unsetenv: Too few arguments.\n"
# define DIVZERO	"Floating exception\n"
# define DIVZERO_CORE	"Floating exception (core dumped)\n"
# define SEGFAULT_CORE	"Segmentation fault (core dumped)\n"
# define SEGFAULT	"Segmentation fault\n"
# define NO_PERMISSION	": Permission denied.\n"
# define BINARY		" Binary file not executable.\n"
# define EXEC_ERR	": Exec format error." BINARY
# define FORK_ERR	"Error : Issue creating process.\n"

typedef struct	s_cmd
{
  char		**cmd;
  int		mode;
  struct s_cmd	*next;
}		t_cmd;

typedef struct	s_ctrl
{
  int		s;
  int		e;
  int		r;
  int		max;
  int		in;
  int		skip;
  t_cmd		*fdlist;
}		t_ctrl;

typedef struct	s_list
{
  char		*name;
  char		*val;
  struct s_list	*next;
}		t_list;

typedef struct	s_size
{
  int		x;
  int		y;
}		t_size;

typedef struct	s_built
{
  char		*name;
  int		(*p)(char **, t_list **, int *);
}		t_built;

typedef struct  s_sep
{
  char		*cmd;
  int		(*p)(t_cmd **, t_list **, int *);
}		t_sep;

typedef struct	s_alias
{
  char		*name;
  char		*command;
}		t_alias;

typedef struct	s_history
{
  char		*path;
  int		set_hist;
  int		set_save;
  char		*set_prompt;
}		t_history;

enum		e_info
  {
    RUNNING,
    PAUSED,
    STOPPED,
  };

typedef struct	s_jobs
{
  int		index;
  pid_t		pid;
  enum e_info	info;
  struct s_jobs	*next;
  struct s_jobs	*prev;
}		t_jobs;
/*
** Lib
*/
int		my_tablen(char **);
void		my_strcpy(char *, char *);
int		my_tabncmp(char **, char **, const int);
char		**my_arrdup(char **);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_strlen(char *);
char		**my_str_to_wordtab(char *, char);
void		my_putstr(char *);
int		my_puterror(char *, int);
char		*get_next_line(const int);
void		my_putchar(char);
char		*my_strdup(char *);
int		my_atoi(char *);
int		my_printf(char *, ...);
char		*my_strcat(char *, char *);
char		**my_tabcat(char **, char *);

/*
** Fonctions
*/
char		**globing(char **);
char		put_space_next(char *, char *, int *, int *);
char		my_shrc(t_list **, t_alias ***);
char		setalias(char **, t_alias ***);
char		check_unmatch(char *);
char		check_is_num(char *);
char		show_alias(char **, t_alias **);
void		ctr_c();
char		**my_error_hist(char **, int *);
char		check_hist_cmd(char **);
char		**my_unalias(char **, t_alias ***);
void		free_alias(t_alias *);
char		**remove_cmd(char **, char *);
void		put_histo(char **, char *, int *, int *);
char		*get_last_cmd_hist(const int);
char		*get_hist_cmd_pos(const int);
char		write_cmd_hist(t_history *, char **);
char		write_atend_hist(char **, t_history *);
char		**replace_cmd_by_hist(char **, int *);
int		new_size_hist(char **);
int		find_cmdlen_in_hist(const int);
int		find_cmdlen_occ_hist(char *);
char		*find_the_cmd(const int);
char		*find_the_cmdocc(char *);
int		my_open_hist(const char *);
char		**my_history(char **, t_history *);
t_history	*init_history();
char		my_sep_is(const char);
char		verif_pos_sep(char **);
char		**remove_spaces(char **);
char		**parth_sep(char **);
int		new_size_spaces(char **);
int		new_size_sep(char **);
int		new_size_with_exit(char **);
char		is_a_separator(const char);
char		**replace_exit(char **);
char		**remove_cmds(char **);
char		**parsing_cmd_loop(char *, const int);
int		new_size(char **, t_alias **);
char		**replace_alias_by_cmd(char **, t_alias **, const int);
char		verif_alias(char *, t_alias **);
t_alias		*add_alias(char *, const int);
t_alias		**my_add_alias(char *, const int, t_alias **);
char		*my_alias(char *, t_alias ***);
int		len_cmd(char *, const int);
int		count_cmd(char *);
char		**create_tab(char *, t_alias ***);
int		put_error_permission(char *);
int		put_error_fil(char *);
char		*my_separators(char *);
void		my_free_env(t_list *);
void		free_env(t_list *);
void		free_list(t_list *);
void		free_tab(char **);
char		**get_env_table(t_list **);
int		exec_prog(char *, char **, t_list **, int *);
int		my_path(char **, t_list **, int *);
int		input_man(char **, t_list **, int *, int);
void		my_change_pwd(t_list **);
t_list		*list_fill(char **);
char		*my_epurstr(char *, int);
int		separate(char **, t_list **, int *);
int		loop(t_list *, int *, t_alias **);
void		fd_management_two(int *, int);
int		find_next(char **, int *);
int		check_exec(int *);
int		jobs_control(t_cmd **, t_list **, int *);

/*
** Tableaux
*/
int		history(char **, t_list **, int *);
int		my_cd(char **, t_list **, int *);
int		my_setenv(char **, t_list **, int *);
int		my_unsetenv(char **, t_list **, int *);
int		my_env(char **, t_list **, int *);
int		my_echo(char **, t_list **, int *);
int		my_exit(char **, t_list **, int *);

int		semi_colon(t_cmd **, t_list **, int *);
int		pipe_it(t_cmd **, t_list **, int *);
int		dir_to(t_cmd **, t_list **, int *);
int		dir_to_append(t_cmd **, t_list **, int *);
int		dir_from(t_cmd **, t_list **, int *);
int		dir_from_tmp(t_cmd **, t_list **, int *);
int		andand(t_cmd **, t_list **, int *);
int		oror(t_cmd **, t_list **, int *);

#endif /* !MYSH_H_ */
