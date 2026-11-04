/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 19:56:21 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:44 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	char			*cs;
	size_t			i;

	uc = (unsigned char)c;
	cs = (char *)s;
	i = 0;
	while (i < n)
	{
		*cs = uc;
		++cs;
		++i;
	}
	return (s);
}
