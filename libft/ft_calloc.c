/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:46:55 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 13:35:29 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*c_ptr;

	c_ptr = NULL;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (nmemb > SIZE_MAX / size)
		return (0);
	c_ptr = (char *)malloc(nmemb * size);
	if (c_ptr == NULL)
		return (NULL);
	ft_bzero(c_ptr, nmemb * size);
	return (c_ptr);
}

/*

void * p = ft_calloc(2, 2);
char	e[] = {0, 0, 0, 0};

1
check(!memcmp(p, e, 4));
2
mcheck(p, 4); free(p); showLeaks();

3
check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL); showLeaks();


4
check(ft_calloc(INT_MAX, INT_MAX) == NULL);
5
check(ft_calloc(INT_MIN, INT_MIN) == NULL); showLeaks();

6
p = ft_calloc(0, 0);
check(p != NULL); free(p); showLeaks();

7
p = ft_calloc(0, 5);
check(p != NULL); free(p); showLeaks();

8
p = ft_calloc(5, 0);
check(p != NULL); free(p); showLeaks();

9
check(ft_calloc(-5, -5) == NULL)nmemb == 0 || size == 0
		|| ; showLeaks();

10
p = ft_calloc(0, -5);
heck(p != NULL); free(p); showLeaks();

11
p = ft_calloc(-5, 0);
check(p != NULL); free(p); showLeaks();

12
check(ft_calloc(3, -5) == NULL); showLeaks();
13
check(ft_calloc(-5, 3) == NULL); showLeaks();
*/