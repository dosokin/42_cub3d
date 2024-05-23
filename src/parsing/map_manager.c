/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:59:05 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 19:55:43 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	flood_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'o')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	map_manager(t_map_data *data)
{
	char	*not_splitted_map;
	char	**map;
	int		i;

	not_splitted_map = data->file + data->last_info_i;
	if (empty_map(not_splitted_map))
		return (error_manager(NO_MAP));
	if (check_chars(not_splitted_map))
		return (error_manager(INV_CHAR));
	map = create_map(not_splitted_map, &data->size.height);
	if (!map)
		return (1);
	data->map = create_space_map(map, data->size.height);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	flood_spaced_map(data->map);
	if (check_flooded(data->map))
		return (error_manager(WALLS_INT));
	flood_spaces(data->map);
	return (0);
}
