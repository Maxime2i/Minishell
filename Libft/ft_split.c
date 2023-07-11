/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:14:26 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/12 17:14:27 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	count_word(char const *s, char c)
{
	int		nb_word;
	int		is_new_word;
	size_t	i;

	nb_word = 0;
	i = 0;
	is_new_word = 1;
	while (i < ft_strlen(s))
	{
		if (is_new_word == 1 && (s[i] != c
				|| (i == ft_strlen(s) - 1 && s[i] != c)))
		{
			is_new_word = 0;
			nb_word++;
		}
		else if (is_new_word == 0 && s[i] == c)
			is_new_word = 1;
		i++;
	}
	return (nb_word);
}

static int	check(size_t i, char c, int *index, char const *s)
{
	if (s[i] != c && *index < 0)
	{
		*index = i;
		if (i == ft_strlen(s) - 1)
			return (1);
		return (0);
	}
	else if ((i == ft_strlen(s) - 1 || s[i] == c) && *index >= 0)
		return (1);
	return (0);
}

static void	init(size_t *i, int *index, int *indice)
{
	*index = -1;
	*indice = 0;
	*i = 0;
}

char	**ft_split(char const *s, char c)
{
	int		nb_c;
	size_t	i;
	int		index;
	int		indice;
	char	**tab;

	init(&i, &index, &indice);
	nb_c = count_word(s, c);
	tab = malloc((nb_c + 1) * sizeof(*tab));
	if (!tab)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (check(i, c, &index, s) == 1)
		{
			if (i == ft_strlen(s) - 1 && s[i] != c)
				i++;
			tab[indice] = ft_substr(s, index, i - index);
			indice++;
			index = -1;
		}
		i++;
	}
	tab[indice] = NULL;
	return (tab);
}
