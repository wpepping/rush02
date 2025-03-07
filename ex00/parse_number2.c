/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:23:54 by wouter            #+#    #+#             */
/*   Updated: 2025/03/07 11:15:06 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_zeros(int len)
{
	if (len % 3 != 0)
		return (3 - (len % 3));
	else
		return (0);
}

char	*concat_and_free_src(char *dest, char *src, int *buf)
{
	char	*res;

	res = strecat(dest, src, buf);
	free(src);
	return (res);
}

int	match_all(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
