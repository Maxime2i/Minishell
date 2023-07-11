/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:31:25 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/21 18:31:26 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cmd_sub(char **cmd)
{
	char	*path;
	int		status;

	status = 1;
	if (access(cmd[0], F_OK | X_OK) == 0)
	{
		status = execve(cmd[0], cmd, NULL);
		if (status == -1)
			perror("shell");
	}
	else
	{
		path = get_abs_path(cmd);
		if (path)
		{
			status = execve(path, cmd, NULL);
			if (status == -1)
				perror("shell");
			free(path);
		}
		else
			perror("path");
	}
	return (status);
}

void	free_all(char **cmd, t_redirect *red, t_free *fr_s)
{
	free_array(environ);
	free_array(cmd);
	free_red(red);
	while (fr_s->cmd[fr_s->nb_cmd] != NULL)
	{
		free(fr_s->cmd[fr_s->nb_cmd]);
		fr_s->nb_cmd += 1;
	}
	free(fr_s->cmd);
	free(fr_s->exec);
}

void	exec_cmd(char **cmd, int fd[2], t_redirect *red, t_free *fr_s)
{
	int		status;
	char	*c;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		status = exec_cmd_sub(cmd);
		free_all(cmd, red, fr_s);
		close(fd[0]);
		close(fd[1]);
		exit(status);
	}
	else
	{
		wait(&status);
		c = ft_itoa(status);
		exprt_2("?", c);
		exprt("cat=1");
		free(c);
	}
}

char	*get_str(int fd_in)
{
	char	buffer[2046];
	char	*str;
	int		bytes;
	int		i;

	str = malloc(sizeof(*str) * 10000);
	if (!str)
		return (NULL);
	bytes = 1;
	i = 0;
	while (bytes > 0)
	{
		bytes = read(fd_in, &buffer, 100);
		buffer[bytes] = '\0';
		bytes = 0;
		while (buffer[bytes])
			str[i++] = buffer[bytes++];
	}
	str[i] = '\0';
	return (str);
}
