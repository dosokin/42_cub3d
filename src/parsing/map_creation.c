/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:59:05 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 15:33:11 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

char	**create_map(char *not_splitted_map, u_int32_t *line_count)
{
	int		i;
	int		j;
	char	**splitted_map;
	int		biggest_len;

	*line_count = count_lines(not_splitted_map);
	if (!*line_count)
	{
		error_manager(INVMAP);
		return (NULL);
	}
	splitted_map = malloc((*line_count + 1) * sizeof(char *));
	i = 0;
	j = 0;
	biggest_len = get_the_biggest_len(not_splitted_map);
	while (not_splitted_map[j] == '\n')
		j++;
	while ((uint32_t)i < *line_count)
	{
		splitted_map[i] = create_a_map_line(not_splitted_map, &j, biggest_len);
		i++;
	}
	splitted_map[i] = NULL;
	return (splitted_map);
}

char	*map_line_to_spaced(char *map, int line_length)
{
	char	*spaced;
	int		i;

	i = 0;
	spaced = malloc((line_length + 1) * sizeof(char));
	if (!spaced)
		return (NULL);
	spaced[i++] = ' ';
	while (i < line_length - 1)
	{
		spaced[i] = map[i - 1];
		i++;
	}
	spaced[i++] = ' ';
	spaced[i] = 0;
	return (spaced);
}

char	**create_space_map(char **map, int line_count)
{
	char	**spaced_map;
	int		line_length;
	int		j;

	j = 0;
	line_length = ft_strlen(map[0]);
	spaced_map = malloc((line_count + 3) * sizeof(char *));
	if (!spaced_map)
		return (NULL);
	spaced_map[j++] = create_full_space_line(line_length + 2);
	while (j < line_count + 1)
	{
		spaced_map[j] = map_line_to_spaced(map[j - 1], line_length + 2);
		j++;
	}
	spaced_map[j++] = create_full_space_line(line_length + 2);
	spaced_map[j] = NULL;
	return (spaced_map);
}

int	check_chars(char *s)
{
	int		i;
	bool	player_found;

	player_found = false;
	i = 0;
	while (s[i])
	{
		if (is_invalid_map_char(s[i], &player_found))
			return (1);
		i++;
	}
	if (!player_found)
	{
		error_manager(MISS_PLAYER);
		return (1);
	}
	return (0);
}

int	empty_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_whitespace(map[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
