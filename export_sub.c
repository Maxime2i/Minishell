/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:19:37 by dgrandin          #+#    #+#             */
/*   Updated: 2023/07/01 14:19:37 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*environ_add(const char *variable, const char *value, int i)
{
	char	*temp;
	char	*temp_2;

	temp = ft_strjoin(variable, "=");
	if (!temp)
		return (NULL);
	temp_2 = ft_strjoin(temp, value);
	free(temp);
	if (!temp_2)
		return (NULL);
	free(environ[i]);
	environ[i] = temp_2;
	return (temp_2);
}

int	sub_sub_export(char *value, int temp, const char *str, char *variable)
{
	int	len_2;
	int	error;

	len_2 = 0;
	while (str[temp])
		value[len_2++] = str[temp++];
	value[len_2] = '\0';
	error = exprt_2(variable, value);
	free(variable);
	free(value);
	return (error);
}

int	sub_export(int len_1, int len_2, const char *str)
{
	char	*variable;
	char	*value;
	int		temp;

	temp = 0;
	variable = malloc(sizeof(*variable) * len_1);
	if (!variable)
		return (404);
	value = malloc(sizeof(*value) * (len_2 + 1));
	if (!value)
	{
		free(variable);
		return (404);
	}
	while (temp < len_1 - 1)
	{
		variable[temp] = str[temp];
		temp++;
	}
	variable[temp++] = '\0';
	return (sub_sub_export(value, temp, str, variable));
}
