/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:34:32 by wpepping          #+#    #+#             */
/*   Updated: 2024/02/18 21:14:07 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_dictionary(t_entry **dictionary, int n_counter)
{
	int	i;

	i = 0;
	while (i < n_counter)
	{
		if (dictionary[i] != NULL)
		{
			free(dictionary[i]->key);
			free(dictionary[i]->value);
			free(dictionary[i]);
		}
		i++;
	}
	free(dictionary);
}

char	*get_args(int argc, char **argv, char **nbr)
{
	if (argc == 2)
	{
		*nbr = argv[1];
		return ("numbers.dict");
	}
	*nbr = argv[2];
	return (argv[1]);
}

int	main(int argc, char **argv)
{
	char			*file_name;
	char			*nbr;
	int				n_counter;
	struct s_entry	**dictionary;

	if (err0r_handling_1(argc, argv) == 0 && err0r_handling_2(argc, argv) == 0)
	{
		file_name = get_args(argc, argv, &nbr);
		n_counter = count_lines(file_name);
		if (n_counter != -1)
		{
			dictionary = malloc((n_counter + 1) * sizeof(struct s_entry *));
			if (dictionary == NULL)
				ft_putstr("Error");
			else if (read_dict(file_name, dictionary, n_counter) == -1)
				ft_putstr("Dict error");
			else if (parse_number(nbr, dictionary) == -1)
				ft_putstr("Error");
			free_dictionary(dictionary, n_counter);
		}
		else
			ft_putstr("Error");
		ft_putstr("\n");
	}
}
