/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:30:09 by mlangloi          #+#    #+#             */
/*   Updated: 2023/06/30 19:30:12 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokens(t_token *start)
{
	t_token	*current;
	t_token	*next;

	current = start;
	while (current)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int	setenviron(char **env)
{
	int	i;

	i = 0;
	environ = malloc(sizeof(environ) * 100);
	if (!environ)
		return (1);
	while (env[i] != NULL)
	{
		environ[i] = ft_strdup(env[i]);
		i++;
	}
	while (i < 100)
		environ[i++] = NULL;
	return (0);
}

int	verif_cat(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "cat", 3) == 0)
		{
			if (environ[i][4] != '0')
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_parse4(char *str)
{
	str = verif_cheveron(str);
	if (ft_check_error_quotes(str, ft_strlen(str)) == 1)
		return (NULL);
	str = ft_espace_line(str);
	if (!str)
		return (NULL);
	if (str && str[0] == '$')
		str[0] = (char)(-str[0]);
	return (str);
}
