/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:59:58 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/17 11:59:59 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_len_hex(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, c);
		ft_put_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_char(n + '0');
		else
		{
			if (c == 'X')
				ft_char(n - 10 + 'A');
			if (c == 'x')
				ft_char(n - 10 + 'a');
		}
	}
}

int	ft_hex(unsigned int n, const char c)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(n, c);
	len = ft_len_hex(n);
	return (len);
}
