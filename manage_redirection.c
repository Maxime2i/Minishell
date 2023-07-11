/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:03:33 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/14 09:03:35 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirect_sign(char *cmd)
{
	if (ft_strcmp(cmd, "<") == 0
		|| ft_strcmp(cmd, "<<") == 0
		|| ft_strcmp(cmd, ">") == 0
		|| ft_strcmp(cmd, ">>") == 0)
		return (0);
	else
		return (1);
}

char	**get_new_cmd_red(char **cmd, int j)
{
	int		i;
	char	**new_cmd;

	new_cmd = malloc(sizeof(*new_cmd) * (j + 1));
	if (!new_cmd)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (check_redirect_sign(cmd[i]) == 0)
		{
			free(cmd[i++]);
			i++;
		}
		else
			new_cmd[j++] = cmd[i++];
		if (cmd[i - 1] == NULL)
			i--;
	}
	new_cmd[j] = NULL;
	return (new_cmd);
}

char	**remove_red(char **cmd)
{
	int		i;
	int		j;
	char	**new_cmd;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (check_redirect_sign(cmd[i]) == 0)
			j++;
		i++;
	}
	j = i - (j * 2);
	new_cmd = get_new_cmd_red(cmd, j);
	return (new_cmd);
}

t_redirect	*manage_redirection(char **cmd)
{
	int			i;
	t_redirect	*redirect;

	redirect = init_redirect();
	if (!redirect)
		return (NULL);
	i = 0;
	while (cmd[i] != NULL && redirect->error == 0)
	{
		if (ft_strcmp(cmd[i], "<") == 0)
			redirect->error = add_redirect_l(redirect, cmd[i + 1]);
		if (ft_strcmp(cmd[i], "<<") == 0)
			redirect->error = add_redirect_w(redirect, cmd[i + 1]);
		if (ft_strcmp(cmd[i], ">") == 0)
			redirect->error = add_redirect_r(redirect, cmd[i + 1]);
		if (ft_strcmp(cmd[i], ">>") == 0)
			redirect->error = add_redirect_dr(redirect, cmd[i + 1]);
		i++;
	}
	redirect->cmd = remove_red(cmd);
	return (redirect);
}
