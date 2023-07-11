/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:11:37 by dgrandin          #+#    #+#             */
/*   Updated: 2023/04/15 10:11:37 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;

	if (lst)
	{
		while (*lst)
		{
			temp_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = temp_lst;
		}
	}
}
