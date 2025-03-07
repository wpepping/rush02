/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:52:58 by hfriedel          #+#    #+#             */
/*   Updated: 2024/02/18 19:42:24 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	hundreds(char *str, char *dest, int *buffer, t_entry **dictionary)
{
	char	key[2];
	char	*value;

	if (str[0] != '0')
	{
		key[0] = str[0];
		key[1] = '\0';
		value = search_dict(key, dictionary);
		if (value == NULL)
			return (1);
		strecat(dest, value, buffer);
		strecat(dest, " ", buffer);
		value = search_dict("100", dictionary);
		if (value == NULL)
			return (1);
		strecat(dest, value, buffer);
	}
	return (0);
}

int	last(char *str, char *dest, int *buffer, t_entry **dictionary)
{
	char	key[2];
	char	*value;

	if (str[1] != '1' && str[2] != '0')
	{
		if (dest[0] != '\0')
			strecat(dest, " ", buffer);
		key[0] = str[2];
		key[1] = '\0';
		value = search_dict(key, dictionary);
		if (value == NULL)
			return (1);
		strecat(dest, value, buffer);
	}
	return (0);
}

int	second(char *str, char *dest, int *buffer, t_entry **dictionary)
{
	char	key[3];
	char	*value;

	if (str[1] >= '2')
	{
		if (dest[0] != '\0')
			strecat(dest, " ", buffer);
		key[0] = str[1];
		key[1] = '0';
		key[2] = '\0';
		value = search_dict(key, dictionary);
		if (value == NULL)
			return (1);
		strecat(dest, value, buffer);
	}
	return (0);
}

int	teens(char *str, char *dest, int *buffer, t_entry **dictionary)
{
	char	key[3];
	char	*value;

	if (str[1] == '1')
	{
		if (dest[0] != '\0')
			strecat(dest, " ", buffer);
		key[0] = '1';
		key[2] = '\0';
		key[1] = str[2];
		value = search_dict(key, dictionary);
		if (value == NULL)
			return (1);
		strecat(dest, value, buffer);
	}
	return (0);
}

char	*parse_part(char *str, t_entry **dictionary)
{
	char	*dest;
	int		buffer;

	buffer = 100;
	dest = malloc(buffer * sizeof(char));
	dest[0] = '\0';
	if (
		hundreds(str, dest, &buffer, dictionary) == 1
		|| second(str, dest, &buffer, dictionary) == 1
		|| teens(str, dest, &buffer, dictionary) == 1
		|| last(str, dest, &buffer, dictionary) == 1
	)
		return (NULL);
	return (dest);
}
