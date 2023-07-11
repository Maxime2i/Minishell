/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:07:38 by dgrandin          #+#    #+#             */
/*   Updated: 2023/07/08 16:07:39 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_str_cwa(char **cmd)
{
	if ((ft_strcmp(cmd[0], "cat") == 0
			|| ft_strcmp(cmd[0], "/bin/cat") == 0
			|| ft_strcmp(cmd[0], "/usr/bin/cat") == 0)
		&& (cmd[1] == NULL || cmd[1][0] == '-'))
		return (1);
	if ((ft_strcmp(cmd[0], "wc") == 0
			|| ft_strcmp(cmd[0], "/bin/wc") == 0
			|| ft_strcmp(cmd[0], "/usr/bin/wc") == 0)
		&& (cmd[1] == NULL || cmd[1][0] == '-'))
		return (1);
	if ((ft_strcmp(cmd[0], "as") == 0
			|| ft_strcmp(cmd[0], "/bin/as") == 0
			|| ft_strcmp(cmd[0], "/usr/bin/as") == 0)
		&& (cmd[1] == NULL || cmd[1][0] == '-'))
		return (1);
	if ((ft_strcmp(cmd[0], "tail") == 0
			|| ft_strcmp(cmd[0], "/bin/tail") == 0
			|| ft_strcmp(cmd[0], "/usr/bin/tail") == 0))
		return (1);
	if ((ft_strcmp(cmd[0], "sleep") == 0
			|| ft_strcmp(cmd[0], "/bin/sleep") == 0
			|| ft_strcmp(cmd[0], "/usr/bin/sleep") == 0))
		return (1);
	return (0);
}
