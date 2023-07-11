/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:15:25 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/08 14:15:25 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(const char *dir)
{
	if (chdir(dir) == -1)
	{
		exprt_2("?", "1");
		perror("Directory does not exist.\n");
		return (1);
	}
	return (0);
}

void	echo_built(char **command, int fd[2])
{
	int	i;
	int	is_n;

	i = 1;
	is_n = 0;
	while (command[i] && ft_strncmp(command[i], "-n", 100) == 0)
	{
		is_n = 1;
		i++;
	}
	while (command[i] != NULL)
	{
		if (i == 1 && is_n == 1)
			i++;
		write(fd[1], &command[i][0], ft_strlen(command[i]));
		if (command[i + 1])
			write(fd[1], " ", 1);
		i++;
	}
	if (is_n == 0)
		write(fd[1], "\n", 1);
}
