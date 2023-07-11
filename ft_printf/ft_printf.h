/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:53:08 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/17 11:53:09 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include	<stdarg.h>
# include	<limits.h>

int		ft_printf(const char *s, ...);
int		ft_percent(void);
int		ft_hex(unsigned int n, const char c);
int		ft_p(unsigned long n);
int		ft_char(int c);
int		ft_nbr(int n);
int		ft_string(char *s);
int		ft_len_p(unsigned long n);
int		ft_unbr(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);
void	ft_put_p(unsigned long n);

#endif
