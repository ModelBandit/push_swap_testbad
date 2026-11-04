/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:47:35 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:32:41 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_size;
	char	*s_part;

	i = 0;
	str_size = 0;
	if ((size_t)start > ft_strlen(s))
		start = ft_strlen(s);
	else if (len > ft_strlen(s) - (size_t)start)
		str_size = ft_strlen(s) - (size_t)start;
	else
		str_size = len;
	if (str_size == SIZE_MAX)
		return (NULL);
	s_part = (char *)malloc(str_size + 1);
	if (s_part == NULL)
		return (NULL);
	while (i < str_size)
	{
		s_part[i] = s[start];
		++i;
		++start;
	}
	s_part[i] = '\0';
	return (s_part);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s\n", ft_substr("0123456789", 100, 1));
// }

/*
mistakes
1. over allocation
*/