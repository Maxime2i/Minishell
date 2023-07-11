/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:40:07 by mlangloi          #+#    #+#             */
/*   Updated: 2023/06/21 15:13:13 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_parse2(char **tab, t_struct *la_struct, int count, t_token *token)
{
	int		j;

	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = NULL;
	token = la_struct->start;
	j = 0;
	while (token)
	{
		tab[j] = malloc(sizeof(char) * (strlen(token->str) + 1));
		if (!tab[j])
		{
			free_array(tab);
			return (NULL);
		}
		strcpy(tab[j], token->str);
		j++;
		token = token->next;
	}
	return (tab);
}

char	**ft_parse(char *str, t_struct	*la_struct)
{
	char	**tab;
	int		count;
	t_token	*token;

	str = ft_parse4(str);
	if (!str)
		return (NULL);
	la_struct->start = ft_get_tokens(str);
	token = la_struct->start;
	if (verif_fleche(token) == 1)
	{
		free(str);
		return (NULL);
	}
	tab = NULL;
	count = 0;
	token = la_struct->start;
	while (token)
	{
		count++;
		token = token->next;
	}
	tab = ft_parse2(tab, la_struct, count, token);
	ft_parse3(str, tab, la_struct);
	return (tab);
}	

t_token	*ft_get_tokens(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		i;
	int		sep;

	prev = NULL;
	next = NULL;
	i = 0;
	ft_skip_space(line, &i);
	while (line[i])
	{
		sep = ft_ignore_sep(line, i);
		next = next_token(line, &i);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		ft_type_arg(next, sep);
		ft_skip_space(line, &i);
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}

t_token	*next_token2(char *line, int *i, int *j, t_token *token)
{	
	char	c;

	c = ' ';
	while (line[*i] && (line[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)
		{
			c = ' ';
			(*i)++;
		}
		else if (line[*i] == '\\')
		{
			(*i)++;
			token->str[(*j)++] = line[(*i)++];
		}
		else
			token->str[(*j)++] = line[(*i)++];
	}
	return (token);
}

t_token	*next_token(char *line, int *i)
{
	t_token	*token;
	int		j;

	j = 0;
	token = malloc(sizeof (t_token));
	if (!token)
		ft_exit(line, token);
	token->str = malloc(sizeof(char) * ft_next_alloc(line, i));
	if (!token->str)
		ft_exit(line, token);
	token = next_token2(line, i, &j, token);
	token->str[j] = '\0';
	return (token);
}
