/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:19:05 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/13 14:19:10 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static unsigned int	ucount_c(unsigned int nbr)
{	
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static int	count_c(int nbr)
{	
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void	incre(char *str, unsigned int *nbr, int *len)
{
	str[*len] = *nbr % 10 + '0';
	*nbr /= 10;
	*len -= 1;
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	sign;
	int				len;
	char			*str;

	sign = 0;
	nbr = n;
	if (n < 0)
	{
		sign = 1;
		nbr = -n;
	}
	len = count_c(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		incre(str, &nbr, &len);
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	nbr = n;
	len = ucount_c(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		incre(str, &nbr, &len);
	}
	return (str);
}
