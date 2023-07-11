/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd_sub_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:39:36 by dgrandin          #+#    #+#             */
/*   Updated: 2023/07/06 14:39:37 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_error_split(char **cmd, int i)
{
	while (cmd[i] != NULL)
		free(cmd[i++]);
	unlink("temp_redirection_file.txt");
	exprt_2("?", "1");
	return (404);
}

int	error_redirect(char **cmd, t_redirect *redirect)
{
	if (redirect)
		free(redirect);
	free_array(cmd);
	return (405);
}

void	launch_redirection(int pipe, t_redirect *redirect, int *fd)
{
	if (pipe == 1)
		make_redirection(redirect, fd, 1);
	else
		make_redirection(redirect, fd, 0);
}

void	change_red(t_redirect *red)
{
	int	i;

	i = 0;
	while (red->cmd[i])
	{
		if (red->cmd[i][0] == -60)
			red->cmd[i][0] = '<';
		if (red->cmd[i][0] == -62)
			red->cmd[i][0] = '>';
		i++;
	}
}

int	r_error_fd(int fd[2])
{
	if (fd[0] == -2 || fd[1] == -2)
	{
		exprt_2("?", "1");
		return (0);
	}
	else
		return (404);
}
