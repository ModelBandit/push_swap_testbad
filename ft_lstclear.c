/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:56:19 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:11 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	cur = NULL;
	while ((*lst) != NULL)
	{
		cur = *lst;
		(*lst) = (*lst)->next;
		ft_lstdelone(cur, del);
	}
}

// int main()
// {
// 	t_list * l =  ft_lstnew(malloc(1));
// 	for (int i = 0; i < 10; ++i)
// 		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
// 	ft_lstclear(&l, free);
// 	free(malloc(1));
// }