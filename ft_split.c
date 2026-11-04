/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:35:30 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 10:30:58 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*build_set_strtrim(char const *s, char c, size_t *c_count);
static size_t	get_gap(const char **s, int c);
static char		**set_arr(char **s_arr, char const *s, char c, size_t len);
static char		*fill_str(char **s_arr, char const *s, size_t cur_count,
					size_t str_len);

char	**ft_split(char const *s, char c)
{
	char	**ptr_arr;
	char	*s_ptr;
	size_t	c_count;

	c_count = 0;
	s_ptr = build_set_strtrim(s, c, &c_count);
	if (s_ptr == NULL)
		return (NULL);
	ptr_arr = (char **)ft_calloc((c_count + 1), sizeof(char *));
	if (ptr_arr == NULL)
	{
		free(s_ptr);
		return (NULL);
	}
	if (set_arr(ptr_arr, s_ptr, c, c_count) == NULL)
	{
		free(ptr_arr);
		free(s_ptr);
		return (NULL);
	}
	ptr_arr[c_count] = NULL;
	free(s_ptr);
	return (ptr_arr);
}

static char	*build_set_strtrim(char const *s, char c, size_t *c_count)
{
	char		*c_str;
	char const	*s_ptr;

	c_str = (char *)ft_calloc(2, sizeof(char));
	if (c_str == NULL)
		return (NULL);
	c_str[0] = c;
	s_ptr = ft_strtrim(s, (const char *)c_str);
	free(c_str);
	if (s_ptr == NULL)
		return (NULL);
	if (ft_strlen(s_ptr) == 0)
		*c_count = 0;
	else
	{
		c_str = (char *)s_ptr;
		while (c_str != NULL && *c_str != '\0')
		{
			++(*c_count);
			while (*c_str == c)
				++c_str;
			c_str = ft_strchr(c_str, c);
		}
	}
	return ((char *)s_ptr);
}

static size_t	get_gap(const char **s, int c)
{
	size_t	str_len;
	char	*end_ptr;

	str_len = 0;
	end_ptr = ft_strchr((*s), c);
	while (end_ptr != NULL && *(*s) == c)
	{
		++(*s);
		end_ptr = ft_strchr((*s), c);
	}
	if (end_ptr == NULL)
		end_ptr = ft_strchr((*s), '\0');
	while (&((*s)[str_len]) != &(end_ptr[0]))
		++str_len;
	return (str_len);
}

static char	**set_arr(char **s_arr, char const *s, char c, size_t len)
{
	size_t	cur_count;
	size_t	str_len;

	cur_count = 0;
	str_len = 0;
	while (cur_count < len)
	{
		str_len = get_gap(&s, c);
		s = fill_str(s_arr, s, cur_count, str_len + 1);
		if (s == NULL)
			return (NULL);
		else if (*s != '\0')
			++s;
		++cur_count;
	}
	return (s_arr);
}

static char	*fill_str(char **s_arr, char const *s, size_t cur_count,
		size_t str_len)
{
	size_t	i;

	i = 0;
	if (str_len == 0)
	{
		s_arr[cur_count] = NULL;
		return ((char *)&(s[str_len]));
	}
	s_arr[cur_count] = (char *)malloc(str_len);
	if (s_arr[cur_count] == NULL)
	{
		while (i < cur_count)
		{
			free(s_arr[i]);
			++i;
		}
		return (NULL);
	}
	ft_strlcpy(s_arr[cur_count], s, str_len);
	return ((char *)&(s[str_len - 1]));
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "Z";
// 	char **tab = ft_split(s, 'a');
// 	int i = 0;

// 	while (tab[i] != NULL)
// 	{
// 		printf("%d - \"%s\"\n", i, tab[i]);
// 		free(tab[i]);
// 		++i;
// 	}
// 	free(tab[i]);
// 	free(tab);
// }

/*
make touble ft_strtrim("Z", "a");
*/

/*

void	nothing(void)
{
	char	**ptr_arr;
	char	*s_ptr;
	char	*c_str;
	size_t	c_count;
	size_t	cur_count;
	size_t	str_len;
		size_t	i;

	c_count = -1;
	c_str = (char *)ft_calloc(2, sizeof(char));
	if (c_str == NULL)
		return (NULL);
	c_str[0] = c;
	s_ptr = ft_strtrim(s, (const char *)c_str);
	s_ptr_copy = NULL;
	free(c_str);
	if (s_ptr == NULL)
		return (NULL);
	if (ft_strlen(s_ptr) == 0)
		*c_count = 0;
	else
	{
		s_ptr_copy = s_ptr;
		while (s_ptr_copy != NULL && *s_ptr_copy != '\0')
		{
			++(*c_count);
			while (*s_ptr_copy == c)
				++s_ptr_copy;
			s_ptr_copy = ft_strchr(s_ptr_copy, c);
		}
	}
	return ((char *)s_ptr);
	if (s_ptr == NULL)
		return (NULL);
	ptr_arr = (char **)malloc((c_count + 1) * sizeof(char *));
	if (ptr_arr == NULL)
		return (NULL);
	if (set_arr(ptr_arr, s_ptr, c, c_count) == NULL)
	{
		free(ptr_arr);
		return (NULL);
	}
	cur_count = 0;
	str_len = 0;
	while (cur_count < len)
	{
		str_len = get_gap(&s, c);
		s = fill_str(s_arr, s, cur_count, str_len + 1);
		i = 0;
		if (str_len == 0)
		{
			s_arr[cur_count] = NULL;
			return ((char *)&(s[str_len]));
		}
		s_arr[cur_count] = (char *)malloc(str_len);
		if (s_arr[cur_count] == NULL)
		{
			while (i < cur_count)
			{
				free(s_arr[i]);
				++i;
			}
			return (NULL);
		}
		ft_strlcpy(s_arr[cur_count], s, str_len);
		return ((char *)&(s[str_len - 1]));
			if (s == NULL)
				return (NULL);
			else if (*s != '\0')
				++s;
			++cur_count;
		}
		return (s_arr);
	ptr_arr[c_count] = NULL;
	free(s_ptr);
	return (ptr_arr);
}

*/