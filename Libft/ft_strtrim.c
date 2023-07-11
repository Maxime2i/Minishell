/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:51:27 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/13 13:52:02 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static unsigned int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	int		end;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (s1[end - 1] && is_in_set(s1[end - 1], set))
		end--;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	str = malloc((end - start + 1) * sizeof(*str));
	if (str)
		ft_strlcpy(str, &s1[start], end - start + 1);
	else
		return (NULL);
	return (str);
}

/*int	main(void)
{
	char a[] = "   Test Mon Code   ";
	char b[] = "   ";
	printf("%s\n", ft_strtrim(a, b));
	return (0);
}*/
