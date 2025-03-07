/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:43:41 by auspensk          #+#    #+#             */
/*   Updated: 2024/03/22 11:32:05 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_lines(char *file_name)
{
	int		n_counter;
	char	t;
	char	prev_t;
	int		bytes_read;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	n_counter = 0;
	prev_t = '\n';
	bytes_read = read(fd, &t, 1);
	while (bytes_read != 0)
	{
		prev_t = t;
		bytes_read = read(fd, &t, 1);
		if (t == '\n' && prev_t != '\n')
			n_counter ++;
	}
	close (fd);
	return (n_counter);
}

char	*read_key(int fd)
{
	char	t;
	char	*key;
	int		bytes_read;
	int		k;

	k = 0;
	key = (char *) malloc(100 * sizeof(char));
	if (read_sign(fd, &t, &bytes_read) == -1)
		key[k++] = '-';
	while (t >= '0' && t <= '9' && bytes_read > 0)
	{
		key[k++] = t;
		bytes_read = read(fd, &t, 1);
	}
	key[k] = '\0';
	if (t != ':'
		&& (t != ' ' || first_char_after_spaces(fd, &t) == 0 || t != ':'))
		return (NULL);
	return (key);
}

char	*read_value(int fd)
{
	char	t;
	char	*value;
	int		bytes_read;
	int		k;

	bytes_read = first_char_after_spaces(fd, &t);
	k = 0;
	value = (char *) malloc(100 * sizeof(char));
	while (t != '\n' && bytes_read != 0)
	{
		if (t < 32 || t > 126)
			return (NULL);
		value[k] = t;
		k++;
		bytes_read = read(fd, &t, 1);
	}
	value[k] = '\0';
	return (value);
}

int	read_dict(char *file_name, t_entry **dict, int n_counter)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	dict[0] = 0;
	while (i < n_counter)
	{
		dict[i] = malloc(2 * sizeof(char *));
		dict[i]->key = read_key(fd);
		dict[i + 1] = 0;
		if (dict[i]->key == NULL || search_dict(dict[i]->key, dict) != NULL)
			return (close_file_and_error(fd));
		dict[i]->value = read_value(fd);
		if (dict[i]->value == NULL)
			return (close_file_and_error(fd));
		i++;
	}
	return (0);
}
