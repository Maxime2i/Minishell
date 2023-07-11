/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:59:46 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/13 13:59:50 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*int	main(void)
{
	char	s[] = "Test Mon Code";
	int fd = open("test", O_WRONLY);
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
}*/
