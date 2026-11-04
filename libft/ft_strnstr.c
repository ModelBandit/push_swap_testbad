/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 10:00:51 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:32:21 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_string(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	b_len;
	size_t	l_len;

	i = 0;
	b_len = ft_strlen(big);
	l_len = ft_strlen(little);
	if (l_len <= 0)
		return ((char *)big);
	else if (len <= 0 || b_len <= 0)
		return (NULL);
	while (i < len && i <= b_len)
	{
		if (big[i] == little[0])
		{
			if (check_string(&big[i], little, len - i) > 0)
				return ((char *)(&(big[i])));
		}
		++i;
	}
	return (NULL);
}

static int	check_string(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && big[i] == little[i] && big[i] != '\0'
		&& little[i] != '\0')
	{
		++i;
	}
	if (i <= len && little[i] == '\0')
		return (1);
	return (0);
}

/*
char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j]
				&& big[i + j] != '\0'
				&& little[j] != '\0')
			{
				++j;
			}
			if (little[j] == '\0' && j == ft_strlen((char *)little))
				return (&(((char *)big)[i]));
		}
		++i;
	}
	return (0);
}

*/