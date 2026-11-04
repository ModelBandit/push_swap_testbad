/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:56:37 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/19 16:40:03 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (lst == NULL || *lst == NULL || new == NULL)
		return ;
	cur = *lst;
	if (cur == NULL)
		*lst = new;
	else
	{
		new->next = cur;
		*lst = new;
	}
}
