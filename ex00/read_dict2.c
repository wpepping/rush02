/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:39:13 by auspensk          #+#    #+#             */
/*   Updated: 2024/03/22 10:39:11 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	first_char_after_empty_lines_and_spaces(int fd, char *c)
{
	int		bytes_read;

	bytes_read = read(fd, c, 1);
	while (*c == '\n' && bytes_read > 0)
	{
		bytes_read = read(fd, c, 1);
	}
	while (*c == ' ' && bytes_read > 0)
	{
		bytes_read = read(fd, c, 1);
	}
	return (bytes_read);
}

int	first_char_after_spaces(int fd, char *c)
{
	int		bytes_read;

	bytes_read = read(fd, c, 1);
	while (*c == ' ' && bytes_read > 0)
	{
		bytes_read = read(fd, c, 1);
	}
	return (bytes_read);
}

int	read_sign(int fd, char *c, int *bytes_read)
{
	int	sign;

	sign = 1;
	*bytes_read = first_char_after_empty_lines_and_spaces(fd, c);
	while (*bytes_read > 0 && (*c == '+' || *c == '-'))
	{
		if (*c == '-')
			sign *= -1;
		*bytes_read = read(fd, c, 1);
	}
	return (sign);
}

char	*skip_empty_lines(int fd, char *c)
{
	int		bytes_read;

	bytes_read = read(fd, c, 1);
	while (*c == '\n' && bytes_read > 0)
	{
		bytes_read = read(fd, c, 1);
	}
	if (bytes_read == 0)
		return (NULL);
	else
		return (c);
}

int	close_file_and_error(int fd)
{
	close(fd);
	return (-1);
}
