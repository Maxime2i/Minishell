/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:53:15 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/10 13:53:16 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(char **command, int fd[2])
{
	if (ft_strncmp(command[0], "echo", 100) == 0)
		echo_built(command, fd);
	if (ft_strncmp(command[0], "cd", 100) == 0)
		cd(command[1]);
	if (ft_strncmp(command[0], "pwd", 100) == 0)
		pwd(fd);
	if (ft_strncmp(command[0], "export", 100) == 0)
	{
		if (command[1])
			return (exprt(command[1]));
		else
			exprt_env(fd);
	}
	if (ft_strncmp(command[0], "unset", 100) == 0)
	{
		if (command[1])
			unset(command[1]);
	}
	if (ft_strncmp(command[0], "env", 100) == 0)
		env(fd);
	if (ft_strncmp(command[0], "exit", 100) == 0)
		return (exit_program());
	return (0);
}

int	check_builtin(char *test_command)
{
	if (ft_strncmp(test_command, "echo", 100) == 0)
		return (0);
	if (ft_strncmp(test_command, "cd", 100) == 0)
		return (0);
	if (ft_strncmp(test_command, "pwd", 100) == 0)
		return (0);
	if (ft_strncmp(test_command, "export", 100) == 0)
		return (0);
	if (ft_strncmp(test_command, "unset", 100) == 0)
		return (0);
	if (ft_strncmp(test_command, "env", 100) == 0)
		return (0);
	if (ft_strncmp(test_command, "exit", 100) == 0)
		return (0);
	return (1);
}
