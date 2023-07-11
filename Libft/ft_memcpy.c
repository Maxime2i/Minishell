/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:51:50 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/11 11:51:52 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*p_dest;

	p_dest = dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
	{
		*((char *)dest) = *((char *)src);
		dest++;
		src++;
	}
	return (p_dest);
}
