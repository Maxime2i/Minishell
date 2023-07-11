/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:40:07 by mlangloi          #+#    #+#             */
/*   Updated: 2023/06/06 15:40:21 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_skip_space(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t'
		|| line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f')
		(*i)++;
}

int	ft_is_sep(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr("<>|", line[i]))
		return (0);
	else if (ft_strchr("<>|", line[i]) && ft_check_quotes(line, i) == 0)
		return (1);
	else
		return (0);
}

int	ft_ignore_sep(char *line, int i)
{
	if (line[i] && line[i] == '\\' && line[i + 1] && line[i + 1] == '|')
		return (1);
	else if (line[i] && line[i] == '\\' && line[i + 1] && line[i + 1] == '>')
		return (1);
	else if (line[i] && line[i] == '\\' && line[i + 1]
		&& line[i + 1] == '>' && line[i + 2] && line[i + 2] == '>')
		return (1);
	return (0);
}

int	ft_next_alloc(char *line, int *i)
{
	int		count;
	int		j;
	char	c;

	count = 0;
	j = 0;
	c = ' ';
	while (line[*i + j] && (line[*i + j] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i + j] == '\'' || line[*i + j] == '\"'))
			c = line[*i + j++];
		else if (c != ' ' && line[*i + j] == c)
		{
			count = count + 2;
			c = ' ';
			j++;
		}
		else
			j++;
		if (line[*i + j] == '\\')
			count--;
	}
	return (j - count + 1);
}
