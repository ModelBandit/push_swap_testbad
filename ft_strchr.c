/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:43:36 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:31:53 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sp;
	size_t	i;
	size_t	size;

	sp = (char *)s;
	i = 0;
	size = ft_strlen(sp);
	while (i <= size)
	{
		if ((unsigned char)sp[i] == (unsigned char)c)
			return (&(sp[i]));
		++i;
	}
	return (0);
}
