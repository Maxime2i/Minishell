/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:30:11 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/08 17:30:11 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exprt_env(int fd[2])
{
	int	i;

	i = 0;
	while (environ[i])
	{
		ft_putstr("declare -x ", fd[1]);
		ft_putstr(environ[i], fd[1]);
		write(fd[1], "\n", 1);
		i++;
	}
	return (0);
}

int	exprt_2(const char *variable, const char *value)
{
	int		i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], variable, ft_strlen(variable)) == 0)
		{
			if (environ_add(variable, value, i) == NULL)
				return (404);
			break ;
		}
		i++;
	}
	if (environ[i] == NULL)
	{
		if (environ_add(variable, value, i) == NULL)
			return (404);
		environ[i + 1] = NULL;
	}
	return (0);
}

int	exprt(const char *str)
{
	int		len_1;
	int		len_2;

	len_1 = 0;
	while (str[len_1] != '=' && str[len_1])
		len_1++;
	if (str[len_1] == '=')
		len_1++;
	else
		return (0);
	len_2 = 0;
	while (str[len_1 + len_2])
		len_2++;
	return (sub_export(len_1, len_2, str));
}

int	unset(const char *variable)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], variable, ft_strlen(variable)) == 0)
		{
			free(environ[i]);
			while (environ[i + 1] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			environ[i] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}
