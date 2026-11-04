/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:12:37 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:41 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_from_head(char **dst, char **src, size_t len);
static void	set_from_tail(char **dst, char **src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;

	if (dst == NULL || src == NULL)
		return (NULL);
	if (n == 0)
		return (dst);
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_dst > c_src)
	{
		set_from_tail(&c_dst, &c_src, n);
	}
	else
	{
		set_from_head(&c_dst, &c_src, n);
	}
	return (dst);
}

static void	set_from_head(char **dst, char **src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(*dst)[i] = (*src)[i];
		++i;
	}
}

static void	set_from_tail(char **dst, char **src, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i > 0)
	{
		(*dst)[i] = (*src)[i];
		--i;
	}
	(*dst)[0] = (*src)[0];
}
