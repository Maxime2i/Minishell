/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:50:04 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/11 14:50:05 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len_s;
	char	*str;

	len_s = ft_strlen(s);
	i = 0;
	str = malloc((len_s + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (i < len_s)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
