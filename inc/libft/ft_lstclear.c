/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:51:48 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/08 18:54:48 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!lst || !del)
		return ;
	list = *lst;
	temp = *lst;
	while (list)
	{
		temp = temp->next;
		del(list->content);
		free(list);
		list = temp;
	}
	*lst = 0;
}
