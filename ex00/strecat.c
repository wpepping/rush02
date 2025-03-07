/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strecat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:47:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/03/22 11:26:02 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*extstr(char *src, int buffer)
{
	char	*result;

	result = ft_strbuf(buffer);
	ft_strcpy(result, src);
	free(src);
	return (result);
}

char	*strecat(char *dest, char *src, int *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i += 1;
	while (src[j] != '\0')
	{
		if (i + j + 2 > *buffer)
		{
			*buffer = *buffer * 2;
			dest = extstr(dest, *buffer);
		}
		dest[i + j] = src[j];
		j += 1;
	}
	dest[i + j] = '\0';
	return (dest);
}
