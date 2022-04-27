/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:47:01 by bdurmus           #+#    #+#             */
/*   Updated: 2022/02/09 12:46:46 by bdurmus          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*array;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		array = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = array;
	}
	*lst = NULL;
}
