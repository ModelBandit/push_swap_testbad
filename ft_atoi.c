/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 10:49:52 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 13:35:19 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_tokens(char c, char *tokens);

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		oper;
	int		num;

	str = (char *)nptr;
	oper = 1;
	num = 0;
	while (check_tokens(*str, " \t\n\v\f\r") > 0)
		++str;
	if (ft_strlen(nptr) > 0 && ft_strncmp(nptr, "-2147483648",
			ft_strlen(nptr)) == 0)
		return (INT_MIN);
	if (check_tokens(*str, "+-") > 0)
	{
		if (*str == '-')
			oper = oper * -1;
		++str;
	}
	while (check_tokens(*str, "0123456789") > 0)
	{
		num = num * 10;
		num += *str - '0';
		++str;
	}
	return (num * oper);
}

static int	check_tokens(char c, char *tokens)
{
	while (*tokens != '\0')
	{
		if (c == *tokens)
			return (1);
		++tokens;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	if(ft_atoi("") == 0)
// 		printf("true\n");
// 	return (0);
// }