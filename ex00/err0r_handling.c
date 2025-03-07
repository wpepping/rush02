/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err0r_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:49:29 by hfriedel          #+#    #+#             */
/*   Updated: 2024/02/18 15:30:36 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	err0r_handling_1(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1 || argc > 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
			{
				ft_putstr("Error\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	err0r_handling_2(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (!(argv[2][i] >= '0' && argv[2][i] <= '9'))
			{
				ft_putstr("Error\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}
