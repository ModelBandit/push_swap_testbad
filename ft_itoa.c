/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:21:22 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:04 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_count(int n);
static char		*fill_itoa(char *n_str, size_t len, int n);

char	*ft_itoa(int n)
{
	char	*n_str;
	size_t	str_len;

	n_str = NULL;
	str_len = 0;
	if (n == 0)
	{
		n_str = ft_calloc(sizeof(char), 2);
		if (n_str == NULL)
			return (NULL);
		n_str[0] = '0';
		return (n_str);
	}
	str_len = size_count(n);
	return (fill_itoa(n_str, str_len, n));
}

static size_t	size_count(int n)
{
	size_t	str_len;

	str_len = 0;
	if (n < 0)
		++str_len;
	while (n != 0)
	{
		++str_len;
		n = n / 10;
	}
	return (str_len);
}

static char	*fill_itoa(char *n_str, size_t len, int n)
{
	n_str = ft_calloc(sizeof(char), len + 1);
	if (n_str == NULL)
		return (NULL);
	if (n == INT_MIN)
	{
		n_str[0] = '-';
		n_str[len - 1] = '0' + (INT_MAX % 10) + 1;
		n = n / 10;
		n *= -1;
		--len;
	}
	else if (n < 0)
	{
		n_str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		n_str[len - 1] = '0' + (n % 10);
		n = n / 10;
		--len;
	}
	return (n_str);
}
