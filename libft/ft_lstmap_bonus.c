/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:48 by soutchak          #+#    #+#             */
/*   Updated: 2023/11/06 22:30:01 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));

static t_list	*ft_lstmap2(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*new_node;
	t_list	*head;

	tmp = l;
	head = NULL;
	prev = NULL;
	while (tmp)
	{
		new_node = ft_lstnew(f(tmp->content));
		if (!new_node)
		{
			ft_lstclear(&head, d);
			return (NULL);
		}
		if (!head)
			head = new_node;
		if (prev)
			prev->next = new_node;
		prev = new_node;
		tmp = tmp->next;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!lst || !f || !del)
		return (NULL);
	return (ft_lstmap2(lst, f, del));
}
