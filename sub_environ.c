/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:44:59 by dgrandin          #+#    #+#             */
/*   Updated: 2023/07/05 11:45:00 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*init_new_cmd(char *var, char *cmd)
{
	char	*new_cmd;

	(void)cmd;
	new_cmd = malloc(sizeof(*new_cmd) * (ft_strlen(cmd) + ft_strlen(var) + 2));
	if (!new_cmd)
	{
		free(var);
		return (NULL);
	}
	return (new_cmd);
}

int	sub_check_arg(char **cmd, int i)
{
	char	*var;

	var = change_arg(cmd[i]);
	if (!var)
		return (1);
	var = get_cmd_with_var(cmd[i], var);
	if (!var)
		return (1);
	cmd[i] = var;
	var = NULL;
	return (0);
}
