/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:32 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/17 11:54:33 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_unbr(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_uitoa(n);
	len = ft_string(str);
	free(str);
	return (len);
}

int	ft_nbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_string(str);
	free(str);
	return (len);
}
