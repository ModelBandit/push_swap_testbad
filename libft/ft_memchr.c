/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:08:36 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:30 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sp;
	size_t	i;

	if (n <= 0)
		return (0);
	sp = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)sp[i] == (unsigned char)c)
			return (&(sp[i]));
		++i;
	}
	return (0);
}
