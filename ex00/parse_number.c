/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:49:49 by wpepping          #+#    #+#             */
/*   Updated: 2025/03/07 11:14:31 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_part(char *result, char **str, int zeros)
{
	int		i;

	i = 0;
	while (i < zeros)
	{
		result[i] = '0';
		i += 1;
	}
	while (i < 3)
	{
		result[i] = (**str);
		*str += 1;
		i += 1;
	}
	return (result);
}

char	*get_thousands(int zeros, t_entry **dict)
{
	char	*index;
	char	*result;
	int		i;

	index = malloc((zeros + 2) * sizeof(char));
	if (index == NULL)
		return (NULL);
	index[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		index[i] = '0';
		i++;
	}
	index[i] = '\0';
	result = search_dict(index, dict);
	free(index);
	return (result);
}

char	*get_thousands_and_part(char **nbr, t_entry **dict, char part[3])
{
	char	*temp_str;
	char	*res;
	int		buf;

	buf = 128;
	res = ft_strbuf(buf);
	if (ft_strcmp(part, "000") != 0)
	{
		temp_str = get_thousands(ft_strlen(*nbr), dict);
		if (temp_str == NULL)
			return (NULL);
		res = strecat(strecat(res, " ", &buf), temp_str, &buf);
	}
	temp_str = parse_part(get_part(part, nbr, 0), dict);
	if (temp_str == NULL)
		return (NULL);
	if (temp_str[0] != '\0')
		res = strecat(strecat(res, " ", &buf), temp_str, &buf);
	free(temp_str);
	return (res);
}

int	parse_non_zero(char *nbr, t_entry **dict)
{
	int		len;
	char	part[3];
	char	*temp_str;
	char	*res;
	int		buf;

	len = ft_strlen(nbr);
	buf = 128;
	res = malloc(128 * sizeof(char));
	res[0] = '\0';
	temp_str = parse_part(get_part(part, &nbr, get_zeros(len)), dict);
	if (temp_str == NULL)
		return (-1);
	res = concat_and_free_src(res, temp_str, &buf);
	while (*nbr != '\0')
	{
		temp_str = get_thousands_and_part(&nbr, dict, part);
		if (temp_str == NULL)
			return (-1);
		res = concat_and_free_src(res, temp_str, &buf);
	}
	ft_putstr(res);
	free(res);
	return (0);
}

int	parse_number(char *nbr, t_entry **dict)
{
	if (nbr[0] && match_all(nbr, '0'))
	{
		ft_putstr("zero");
		return (0);
	}
	return (parse_non_zero(nbr, dict));
}
