/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:40:07 by mlangloi          #+#    #+#             */
/*   Updated: 2023/06/21 15:20:14 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotes(char *line, int index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (line[i] && i <= index)
	{
		if (k == 0 && line[i] == '\"')
			k = 2;
		else if (k == 0 && line[i] == '\'')
			k = 1;
		else if (k == 2 && line[i] == '\"')
			k = 0;
		else if (k == 1 && line[i] == '\'')
			k = 0;
		i++;
	}
	return (k);
}

int	ft_check_error_quotes(char *line, int index)
{
	int		k;
	int		i;

	i = 0;
	k = ft_check_quotes(line, index);
	while (line[i] && i <= index)
	{
		if (line[i] == '\\')
			return (1);
		i++;
	}
	if (k != 0)
	{
		ft_printf("Error : quotes !\n");
		return (1);
	}
	return (0);
}

char	*ft_espace_line2(char *line, int *j, int *i, char *new)
{
	int	fleche;

	new[(*j)++] = ' ';
	new[(*j)++] = line[(*i)++];
	if (ft_check_quotes(line, (*i)) == 0 && (line[(*i)] == '>'
			|| line[(*i)] == '<'))
	{
		fleche = 1;
		while (line[(*i)] == '>' || line[(*i)] == '<')
		{
			new[(*j)++] = line[(*i)++];
			fleche++;
		}
		if (fleche > 2)
		{
			ft_printf("Error : Trop de flèches consécutives.\n");
			free(new);
			return (NULL);
		}
		else if (line[(*i)] && line[(*i)] != ' ')
			new[(*j)++] = ' ';
	}
	else if (line[(*i)] && line[(*i)] != ' ')
		new[(*j)++] = ' ';
	return (new);
}

char	*ft_espace_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(line) * 2 + 1));
	if (!new)
		ft_exit1(line);
	while (new && line[i])
	{
		if (ft_check_quotes(line, i) != 1 && line[i] == '$' && i
			&& line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);
		else if (ft_check_quotes(line, i) == 0 && ft_is_sep(line, i))
			new = ft_espace_line2(line, &j, &i, new);
		else
			new[j++] = line[i++];
		if (!new)
			return (NULL);
	}
	new[j] = '\0';
	free(line);
	return (new);
}

void	ft_type_arg(t_token *token, int sep)
{
	if (ft_strcmp(token->str, "") == 0)
		token->type = 0;
	else if (ft_strcmp(token->str, ">") == 0 && sep == 0)
		token->type = 3;
	else if (ft_strcmp(token->str, ">>") == 0 && sep == 0)
		token->type = 4;
	else if (ft_strcmp(token->str, "<") == 0 && sep == 0)
		token->type = 5;
	else if (ft_strcmp(token->str, "<<") == 0 && sep == 0)
		token->type = 6;
	else if (ft_strcmp(token->str, "|") == 0 && sep == 0)
		token->type = 7;
	else if (token->prev == NULL || token->prev->type >= 3)
		token->type = 1;
	else
		token->type = 2;
}
