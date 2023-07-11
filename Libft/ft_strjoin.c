/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:59:49 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/12 16:59:51 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = -1;
	while (i++ < s1_len - 1)
		str[i] = s1[i];
	j = -1;
	while (j++ < s2_len - 1)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
