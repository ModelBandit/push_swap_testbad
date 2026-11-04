/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:11:19 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:32:15 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len == SIZE_MAX)
		return (NULL);
	new_str = (char *)ft_calloc(sizeof(char), s_len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		new_str[i] = f(i, s[i]);
		++i;
	}
	return (new_str);
}
