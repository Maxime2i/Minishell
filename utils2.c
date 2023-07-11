/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:27:25 by mlangloi          #+#    #+#             */
/*   Updated: 2023/07/06 13:27:27 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_is_good(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

void	ft_exit2(char *str, t_token *token, char **cmd)
{
	if (cmd)
		free_array(cmd);
	if (token)
		ft_free_tokens(token);
	if (str)
		free(str);
	if (environ)
		free_array(environ);
	exit(0);
}

void	ft_exit1(char *str)
{
	if (str)
		free(str);
	if (environ)
		free_array(environ);
	exit(0);
}

void	ft_parse3(char	*str, char **tab, t_struct *la_struct)
{
	if (!tab)
		ft_exit2(str, la_struct->start, tab);
	ft_free_tokens(la_struct->start);
	free(str);
}

char	*verif_cheveron(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i > 0) && (str[i - 1] == '"'
				|| str[i - 1] == '\'')
			&& (str[i] == '<' || str[i] == '>'))
		{
			str[i] = (char)(-str[i]);
		}
		i++;
	}
	return (str);
}
