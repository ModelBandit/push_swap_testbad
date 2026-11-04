/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:55:12 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:21 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstsafemap(t_list *lst, t_list **new_list,
					void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new_lst;
	void	*data;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	cur = NULL;
	data = f(lst->content);
	if (data == NULL)
		return (NULL);
	new_lst = ft_lstnew(data);
	if (new_lst == NULL)
	{
		del(data);
		return (NULL);
	}
	if (lst->next != NULL)
	{
		cur = ft_lstsafemap(lst, &new_lst, f, del);
		if (cur == NULL)
			return (NULL);
		new_lst->next = cur;
	}
	return (new_lst);
}

static t_list	*ft_lstsafemap(t_list *lst, t_list **new_list,
		void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = ft_lstmap(lst->next, f, del);
	if (new_lst == NULL)
	{
		ft_lstdelone(*new_list, del);
		return (NULL);
	}
	return (new_lst);
}
