/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:05:09 by kirus             #+#    #+#             */
/*   Updated: 2021/10/22 22:12:24 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	st_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while ((*lst)->next)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	del((*lst)->content);
	free(lst);
	free(tmp);
	lst = NULL;
}

static void	st_lstadd_back(t_list **lst, t_list *new)
{
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
}

static t_list	*st_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	**ncond;
	t_list	**nhead;

	nhead = NULL;
	newlst = NULL;
	ncond = NULL;
	while (lst->next)
	{
		newlst = st_lstnew(f(lst->content));
		if (!nhead)
		{
			(*nhead) = newlst;
			ncond = nhead;
		}
		if (!newlst)
		{
			st_lstclear(nhead, del);
			return (NULL);
		}
		st_lstadd_back(ncond, newlst);
		lst = lst->next;
	}
	return (nhead);
}
