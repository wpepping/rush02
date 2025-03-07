/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:41:40 by wpepping          #+#    #+#             */
/*   Updated: 2024/02/18 20:30:41 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*search_dict(char *index, struct s_entry **dictionary)
{
	int	i;

	i = 0;
	while (dictionary[i])
	{
		if (ft_strcmp(index, dictionary[i]->key) == 0)
			return (dictionary[i]->value);
		i++;
	}
	return (NULL);
}
