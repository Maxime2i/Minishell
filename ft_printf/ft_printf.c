/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:09:26 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/15 16:09:26 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_format(va_list arg, const char s)
{
	int	len;	

	len = 0;
	if (!arg)
		return (0);
	if (s == 'c')
		len += ft_char(va_arg(arg, int));
	else if (s == 's')
		len += ft_string(va_arg(arg, char *));
	else if (s == 'p')
		len += ft_p(va_arg(arg, unsigned long));
	else if (s == 'd' || s == 'i')
		len += ft_nbr(va_arg(arg, int));
	else if (s == 'u')
		len += ft_unbr(va_arg(arg, unsigned int));
	else if (s == 'x' || s == 'X')
		len += ft_hex(va_arg(arg, unsigned int), s);
	else if (s == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *s, ...)
{
	size_t	len;
	int		i;
	va_list	list_args;

	va_start (list_args, s);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			len += ft_char(s[i]);
		else
		{
			len += ft_format(list_args, s[i + 1]);
			i++;
		}
		i++;
	}
	va_end(list_args);
	return (len);
}
