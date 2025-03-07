/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:37:02 by wpepping          #+#    #+#             */
/*   Updated: 2025/03/07 11:13:18 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

char	*search_dict(char *index, t_entry **dictionary);
int		ft_strlen(char *str);
int		count_lines(char *file_name);
int		ft_strcmp(char *s1, char *s2);
char	*parse_part(char *str, t_entry **dictionary);
int		parse_number(char *nbr, t_entry **dictionary);
int		read_dict(char *file_name, t_entry **dictionary, int n_counter);
int		err0r_handling_1(int ac, char **str);
int		err0r_handling_2(int ac, char **str);
void	ft_putstr(char *str);
char	*strecat(char *dest, char *src, int *buffer);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strbuf(int buf);
int		read_sign(int fd, char *c, int *bytes_read);
int		first_char_after_spaces(int fd, char *c);
int		close_file_and_error(int fd);
char	*skip_empty_lines(int fd, char *c);
int		get_zeros(int len);
char	*concat_and_free_src(char *dest, char *src, int *buf);
int		match_all(char *str, char c);

#endif
