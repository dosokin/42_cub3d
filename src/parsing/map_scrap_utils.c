/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scrap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:59:05 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 19:55:28 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

int	is_anything_after_the_map(char *not_splitted_map, int i, int c)
{
	while (not_splitted_map[i])
	{
		if (!is_whitespace(not_splitted_map[i]))
			return (0);
		i++;
	}
	return (c);
}

int	count_lines(char *not_splitted_map)
{
	int		i;
	int		c;
	bool	reset;

	reset = true;
	c = 0;
	i = -1;
	while (not_splitted_map[++i])
	{
		if (not_splitted_map[i] == '\n')
		{
			if (c && not_splitted_map[i + 1] == '\n')
				return (is_anything_after_the_map(not_splitted_map, i, c));
			reset = true;
		}
		else if (reset)
		{
			c++;
			reset = false;
		}
	}
	return (c);
}

char	*create_a_map_line(char *not_splitted_map, int *i, int length)
{
	char	*map_line;
	int		j;

	j = 0;
	map_line = malloc((length + 1) * sizeof(char));
	while (not_splitted_map[*i] && not_splitted_map[*i] != '\n')
	{
		map_line[j] = not_splitted_map[*i];
		increment_both(i, &j);
	}
	while (j < length)
	{
		map_line[j] = ' ';
		j++;
	}
	map_line[j] = 0;
	*i = *i + 1;
	return (map_line);
}

int	get_the_biggest_len(char *s)
{
	int	i;
	int	c;
	int	biggest;

	if (!s)
		return (-1);
	i = 0;
	biggest = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (c > biggest)
				biggest = c;
			c = 0;
		}
		else
			c++;
		i++;
	}
	if (c > biggest)
		biggest = c;
	return (biggest);
}

char	*create_full_space_line(int line_length)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(line_length + 1 * sizeof(char));
	while (i < line_length)
	{
		s[i] = ' ';
		i++;
	}
	s[i] = 0;
	return (s);
}
