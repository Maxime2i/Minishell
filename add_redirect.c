/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:46:46 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/21 18:46:47 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_key_word(char *str, char *key_word)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == key_word[0])
		{
			j = 0;
			while (str[i + j] == key_word[j] && key_word[j])
				j++;
			if ((i == 0 || str[i - 1] == '\n')
				&& key_word[j] == '\0'
				&& str[i + j] == '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

int	add_redirect_w(t_redirect *red, char *key_word)
{
	char	buffer[128];
	int		i;
	int		bytes;

	if (!key_word)
		return (-1);
	red->d_left_to_free = key_word;
	i = 0;
	bytes = 0;
	if (red->left)
		red->left = NULL;
	while (ft_find_key_word(red->d_left, key_word) == 1)
	{
		bytes = read(1, &buffer, sizeof(buffer) * 10);
		if (bytes == -1)
			return (-1);
		buffer[bytes] = '\0';
		bytes = 0;
		while (buffer[bytes] != '\0')
			red->d_left[i++] = buffer[bytes++];
		red->d_left[i] = '\0';
	}
	return (0);
}

int	add_redirect_l(t_redirect *red, char *file)
{
	if (!file)
		return (-1);
	red->left = file;
	red->d_left[0] = '\0';
	return (0);
}

int	add_redirect_dr(t_redirect *red, char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (-1);
	while (red->double_right[i] != NULL)
		i++;
	red->double_right[i] = file;
	red->double_right[i + 1] = NULL;
	red->last_right = file;
	return (0);
}

int	add_redirect_r(t_redirect *red, char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (-1);
	while (red->right[i] != NULL)
		i++;
	red->right[i] = file;
	red->right[i + 1] = NULL;
	red->last_right = file;
	return (0);
}
