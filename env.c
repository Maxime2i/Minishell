/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:37:05 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/08 18:37:06 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(int fd[2])
{
	int	i;

	i = 0;
	while (environ[i])
	{
		ft_putstr(environ[i], fd[1]);
		write(fd[1], "\n", 1);
		i++;
	}
	return (0);
}

int	exit_program(void)
{
	return (404);
}

void	ft_putstr(const char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
