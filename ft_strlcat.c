/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:12:38 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:32:06 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strnlen(char *dst, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = my_strnlen(dst, size);
	s_len = ft_strlen((char *)src);
	i = d_len;
	j = 0;
	if (size <= d_len)
		return (size + s_len);
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	if (i < size)
		dst[i] = '\0';
	return (d_len + s_len);
}

static size_t	my_strnlen(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			return (i);
		++i;
	}
	return (i);
}

/*

static size_t	my_strnlen(char *dst, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = my_strnlen(dst, size);
	s_len = ft_strlen(src);
	i = d_len;
	j = 0;
	if (size <= 0)
		return (s_len);
	if (d_len != size)
	{
		while (j < size && src[j] != '\0')
		{
			dst[i] = src[j];
			++i;
			++j;
		}
		dst[i] = '\0';
	}
	if (size < d_len)
		return (size + s_len);
	else
		return (d_len + s_len);
}

static size_t	my_strnlen(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		if (dst[i] == '\0')
			return (i);
		++i;
	}
	return (ft_strlen(dst));
}

*/