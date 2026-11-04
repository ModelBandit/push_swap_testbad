/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:21:23 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:32:03 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_joinstr(char *new_str, char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	size;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == SIZE_MAX || s2_len > SIZE_MAX - s1_len - 1)
		return (NULL);
	size = s1_len + s2_len + 1;
	str = (char *)malloc(size);
	if (str == NULL)
		return (NULL);
	fill_joinstr(str, s1, s2);
	return (str);
}

static void	fill_joinstr(char *new_str, char const *s1, char const *s2)
{
	while (*s1 != '\0')
	{
		*new_str = *s1;
		++new_str;
		++s1;
	}
	while (*s2 != '\0')
	{
		*new_str = *s2;
		++new_str;
		++s2;
	}
	*new_str = '\0';
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char * s = ft_strjoin("tripouille", "42");
//     printf("%d\n", strcmp(s, "tripouille42"));
// }
/*
too less NULL
*/