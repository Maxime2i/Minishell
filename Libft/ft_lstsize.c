/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:51:38 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/15 09:51:39 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb_lst;

	if (!lst)
		return (0);
	nb_lst = 1;
	while (lst->next != NULL)
	{
		nb_lst++;
		lst = lst->next;
	}
	return (nb_lst);
}
