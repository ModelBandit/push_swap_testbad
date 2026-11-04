/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:49:52 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:32:25 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sp;
	size_t	i;

	sp = (char *)s;
	i = ft_strlen(sp);
	while (i > 0)
	{
		if ((unsigned char)sp[i] == (unsigned char)c)
			return (&(sp[i]));
		--i;
	}
	if ((unsigned char)sp[i] == (unsigned char)c)
		return (&(sp[i]));
	return (0);
}
