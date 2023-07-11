/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:58:56 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/10 12:58:57 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_redirection(t_redirect *red, int *fd, int pipe)
{
	int		fd_out;
	int		fd_in;
	int		i;

	if (pipe == 1)
		if_pipe(&fd_in, &fd_out);
	else
		if_not_pipe(&fd_in, &fd_out);
	if (red->left != NULL)
		fd_in = get_left_file(fd_in, red->left);
	if (red->d_left[0] != '\0')
		red_d_left(&fd_in, red);
	i = 0;
	while (red->right[i] != NULL)
		red_right(&fd_out, red, i++);
	i = 0;
	while (red->double_right[i] != NULL)
		red_double_right(&fd_out, red, i++);
	fd[0] = fd_in;
	fd[1] = fd_out;
}

int	manage_exec(char **cmd, int pipe, t_free *fr_s)
{
	t_redirect	*redirect;
	int			fd[2];
	int			r_error;

	r_error = 0;
	redirect = manage_redirection(cmd);
	change_red(redirect);
	if (!redirect || !redirect->cmd)
		return (error_redirect(cmd, redirect));
	cmd = redirect->cmd;
	launch_redirection(pipe, redirect, fd);
	if (fd[0] < 0 || fd[1] < 0)
		r_error = r_error_fd(fd);
	else
	{
		if (check_builtin(cmd[0]) == 0)
			r_error = builtin(cmd, fd);
		else
			exec_cmd(cmd, fd, redirect, fr_s);
	}
	free_array(cmd);
	free_red(redirect);
	return (r_error);
}

int	sub_manage_split(char **exec, char **cmd, int i, t_free *fr_s)
{
	if (check_arg(exec) == 0)
	{
		if (cmd[i] == NULL || cmd[i + 1] == NULL)
			return (manage_exec(exec, 0, fr_s));
		else
		{
			free(cmd[i]);
			return (manage_exec(exec, 1, fr_s));
		}
	}
	else
	{
		free_array(exec);
		if (!(cmd[i] == NULL || cmd[i + 1] == NULL))
			free(cmd[i]);
		return (405);
	}
}

int	manage_split_sub(char **exec, char **cmd, t_free *free_son, int *i)
{
	int	j;

	j = 0;
	while (cmd[*i] != NULL && j != 404)
	{
		j = 0;
		while (cmd[*i] != NULL && cmd[*i][0] != '|')
		{
			exec[j] = cmd[*i];
			j++;
			*i += 1;
		}
		exec[j] = NULL;
		if (cmd[*i] == NULL)
			free_son->nb_cmd = *i;
		else
			free_son->nb_cmd = *i + 1;
		j = sub_manage_split(exec, cmd, *i, free_son);
		if (cmd[*i] != NULL)
			*i += 1;
		if (j >= 404)
			break ;
		unlink("temp_redirection_file.txt");
	}
	return (j);
}

int	manage_split(char **cmd)
{
	char	**exec;
	t_free	free_son;
	int		j;
	int		i;

	i = 0;
	exec = malloc(sizeof(*exec) * 100);
	if (exec)
	{
		free_son.exec = exec;
		free_son.cmd = cmd;
		j = manage_split_sub(exec, cmd, &free_son, &i);
		if (j != 405)
			free(exec);
		unlink("pipe.txt");
	}
	else
		j = 404;
	if (j >= 404)
		return (free_error_split(cmd, i));
	return (0);
}
