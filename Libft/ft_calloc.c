/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:21:24 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/11 14:21:24 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == (size_t)-1 || size == (size_t)-1
		|| nmemb * size == (size_t)-1)
		return (NULL);
	tab = malloc(((nmemb) * size));
	if (!tab)
		return (tab);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
