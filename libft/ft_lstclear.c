/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivet <arivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:40:52 by arivet            #+#    #+#             */
/*   Updated: 2026/05/27 13:43:13 by arivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todel;

	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			todel = *lst;
			del(todel->content);
			*lst = todel->next;
			free(todel);
		}
	}
	*lst = NULL;
}
