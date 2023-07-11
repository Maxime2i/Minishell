/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:00 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/12 16:27:02 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_env(int nb)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	while (environ[nb][i] != '=')
		i++;
	i++;
	while (environ[nb][i + j])
		j++;
	var = malloc(sizeof(*var) * (j + 1));
	if (!var)
		return (NULL);
	j = 0;
	while (environ[nb][i])
		var[j++] = environ[nb][i++];
	var[j] = '\0';
	return (var);
}

int	check_in_env(char *var)
{
	int	i;
	int	len;

	i = 0;
	while (environ[i])
	{
		len = 0;
		while (environ[i][len] != '=')
			len++;
		len--;
		if (ft_strcmp_env(environ[i], var) == 0)
		{
			free(var);
			return (i);
		}
		i++;
	}
	free(var);
	return (-1);
}

char	*change_arg(char *cmd)
{
	int		i;
	int		j;
	char	nb_env;
	char	*var;

	i = 0;
	j = 0;
	while (cmd[i] != -36)
		i++;
	i++;
	while (cmd[i + j] != ' ' && cmd[i + j])
		j++;
	var = malloc(sizeof(*var) * (j + 1));
	if (!var)
		return (NULL);
	j = 0;
	while (cmd[i] != ' ' && cmd[i])
		var[j++] = cmd[i++];
	var[j] = '\0';
	nb_env = check_in_env(var);
	if (nb_env != -1)
		var = get_var_env(nb_env);
	else
		var = new_without_var();
	return (var);
}

char	*get_cmd_with_var(char *cmd, char *var)
{
	int		i;
	int		j;
	int		k;
	char	*new_cmd;

	i = 0;
	k = 0;
	j = 0;
	new_cmd = init_new_cmd(var, cmd);
	if (!new_cmd)
		return (NULL);
	while (cmd[i] != -36)
		new_cmd[k++] = cmd[i++];
	while (var[j])
		new_cmd[k++] = var[j++];
	while (cmd[i] && cmd[i] != ' ')
		i++;
	while (cmd[i])
		new_cmd[k++] = cmd[i++];
	free(cmd);
	free(var);
	new_cmd[k] = '\0';
	return (new_cmd);
}

int	check_arg(char **cmd)
{
	int		i;
	int		j;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == -36)
			{
				if (sub_check_arg(cmd, i) == 1)
					return (1);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
