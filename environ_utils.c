/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:03:02 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/13 15:03:02 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*new_without_var(void)
{
	char	*var;

	var = malloc(sizeof(*var) * 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	return (var);
}

int	ft_strcmp_env(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s2[i] != s1[i])
			return (1);
		i++;
	}
	if (s1[i] == '=')
		return (0);
	else
		return (1);
}
