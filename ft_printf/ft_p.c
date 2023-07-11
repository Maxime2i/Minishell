/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:11:02 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/17 11:11:03 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_len_p(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_put_p(unsigned long n)
{
	if (n >= 16)
	{
		ft_put_p(n / 16);
		ft_put_p(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_char(n + '0');
		else
			ft_char(n - 10 + 'a');
	}
}

int	ft_p(unsigned long n)
{
	int	len;

	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		len = 2;
		write(1, "0x", 2);
		ft_put_p(n);
		len += ft_len_p(n);
	}
	return (len);
}
