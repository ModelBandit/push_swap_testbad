/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:56:43 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/19 16:17:48 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (lst == NULL || *lst == NULL)
		return ;
	cur = *lst;
	if (cur == NULL)
		*lst = new;
	else
	{
		cur = ft_lstlast(*lst);
		cur->next = new;
	}
}
