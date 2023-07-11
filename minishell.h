/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:30:43 by dgrandin          #+#    #+#             */
/*   Updated: 2023/07/06 16:06:03 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>

extern char	**environ;

typedef struct free_son
{
	char	**cmd;
	char	**exec;
	int		nb_cmd;
}			t_free;

typedef struct redirection
{
	char	*left;
	char	d_left[65536];
	char	*d_left_to_free;
	char	*right[100];
	char	*double_right[100];
	char	*last_right;
	char	**cmd;
	char	**last_cmd;
	int		error;
}			t_redirect;

typedef struct command
{
	char	*command;
	char	**args;
}			t_command;

typedef struct exec_cmd
{
	t_command	*command;
	char		**list_command;
	char		**cmd;
	char		**path_command;
	char		***test_command;
}				t_exec_cmd;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_struct
{
	t_token	*start;
	int		fd;
}			t_struct;

void		ft_exit(char *str, t_token *token);

// parsing.c
t_token		*ft_get_tokens(char *line);
t_token		*next_token(char *line, int *i);
int			ft_next_alloc(char *line, int *i);
void		ft_type_arg(t_token *token, int sep);
char		**ft_parse(char *str, t_struct *la_struct);

// parsing2.c
int			ft_check_quotes(char *line, int index);
int			ft_check_error_quotes(char *line, int index);
char		*ft_espace_line(char *line);

// parsing3.c
void		ft_free_tokens(t_token *start);
void		free_array(char **array);
int			setenviron(char **env);
int			verif_cat(void);
char		*ft_parse4(char *str);

// parse_utils.c
int			ft_strcmp(char *s1, char *s2);
void		ft_skip_space(char *line, int *i);
int			ft_is_sep(char *line, int i);
int			ft_ignore_sep(char *line, int i);

// utils.c
void		handle_signal(int signal);
void		free_red(t_redirect *red);
int			get_left_file(int fd_in, char *file);
int			verif_fleche(t_token *token);

//built-in
void		echo_built(char **command, int fd[2]);
int			builtin(char **command, int fd[2]);
int			check_builtin(char *test_command);
int			cd(const char *dir);
int			pwd(int fd[2]);
int			unset(const char *variable);
int			env(int fd[2]);
int			exprt_env(int fd[2]);
int			exprt(const char *str);
int			ft_strcmp_env(char *s1, char *s2);
int			exprt_2(const char *variable, const char *value);

// utils2.c
void		ft_exit1(char *str);
void		ft_exit2(char *str, t_token *token, char **cmd);
void		ft_parse3(char	*str, char **tab, t_struct *la_struct);
char		*verif_cheveron(char *str);

//make_redirection
void		red_right(int *fd_out, t_redirect *red, int i);
void		red_double_right(int *fd_out, t_redirect *red, int i);
void		red_d_left(int *fd_in, t_redirect *red);
void		if_not_pipe(int *fd_in, int *fd_out);
void		if_pipe(int *fd_in, int *fd_out);

//add_redirect
int			ft_find_key_word(char *str, char *key_word);
int			add_redirect_w(t_redirect *red, char *key_word);
int			add_redirect_l(t_redirect *red, char *file);
int			add_redirect_dr(t_redirect *red, char *file);
int			add_redirect_r(t_redirect *red, char *file);

int			check_filename(char *file);
int			manage_split(char **str);
void		exec_cmd(char **cmd, int fd[2], t_redirect *red, t_free *fr_s);
void		free_red(t_redirect *red);
char		*get_str(int fd_in);
char		*new_without_var(void);
char		*get_abs_path(char **cmd);
void		parse_cmd(const char *cmd, t_command *struc);
int			exit_program(void);
void		ft_putstr(const char *str, int fd);
void		free_tab(char **cmd);
void		free_list(t_command *command);
int			check_arg(char **cmd);
void		free_array(char **array);
int			sub_export(int len_1, int len_2, const char *str);
char		*environ_add(const char *variable, const char *value, int i);
t_redirect	*manage_redirection(char **cmd);
t_redirect	*init_redirect(void);
char		*init_new_cmd(char *var, char *cmd);
int			sub_check_arg(char **cmd, int i);
char		*change_arg(char *cmd);
int			check_in_env(char *var);
char		*get_cmd_with_var(char *cmd, char *var);
int			free_error_split(char **cmd, int i);
int			error_redirect(char **cmd, t_redirect *redirect);
void		launch_redirection(int pipe, t_redirect *redirect, int *fd);
void		make_redirection(t_redirect *red, int *fd, int pipe);
void		change_red(t_redirect *red);
int			r_error_fd(int fd[2]);
int			str_is_good(const char *str);
int			check_str_cwa(char **cmd);

#endif
