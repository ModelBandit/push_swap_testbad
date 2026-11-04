/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 18:11:06 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 13:35:09 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_alloc(size_t ns_start, size_t ns_end);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	ns_start;
	size_t	ns_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	ns_start = 0;
	ns_end = ft_strlen(s1);
	while (ns_start < ns_end && ft_strchr(set, s1[ns_start]) != NULL)
		++ns_start;
	while (ns_start < ns_end && ft_strchr(set, s1[ns_end - 1]) != NULL)
		--ns_end;
	new_str = (char *)my_alloc(sizeof(char), ns_end - ns_start + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, &(s1[ns_start]), ns_end - ns_start + 1);
	return (new_str);
}

static char	*my_alloc(size_t ns_start, size_t ns_end)
{
	if (ns_end == SIZE_MAX && ns_start == 0)
		return (NULL);
	return ((char *)ft_calloc(sizeof(char), ns_end - ns_start + 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "  xxx  xxx  ";
// 	char *set = " ";
// 	char *new_str = ft_strtrim(s, set);

// 	printf("%s\n", new_str);

// 	free(new_str);
// }