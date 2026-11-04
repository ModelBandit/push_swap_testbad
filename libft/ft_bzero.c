/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:23:33 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:29:38 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cs;
	size_t	i;

	cs = s;
	i = 0;
	while (i < n)
	{
		*cs = '\0';
		++cs;
		++i;
	}
}

/*
unsigned int get pass
*/