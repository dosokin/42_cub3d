/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:37:31 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 15:36:09 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_data.h>
#include <map.h>
#include <math.h>
#include <stdlib.h>

t_tile	*add_tile(t_gdata *data, t_map_data *map_data, uint32_t x, uint32_t y)
{
	t_tile_type	type;
	t_tile		*tile;

	type = T_VOID;
	if (map_data->map[y][x] == 'X')
		type = T_VOID;
	else if (map_data->map[y][x] == '1')
		type = T_WALL;
	else if (map_data->map[y][x] == '0')
		type = T_FLOOR;
	tile = tile_new(type, &data->assets);
	return (tile);
}

double	map_fgrid_pos(t_map *map, double pos)
{
	return (floor(pos / map->grid_size));
}

t_map	map_new(t_gdata *data, t_map_data *map_data)
{
	uint32_t	y;
	uint32_t	x;
	t_map		map;

	map = (t_map){.size = map_data->size,
		.grid_size = 64,
		.grid = malloc(map_data->size.height * sizeof(t_tile **))};
	y = 0;
	while (y < map.size.height)
	{
		map.grid[y] = malloc(map.size.width * sizeof(t_tile *));
		x = 0;
		while (x < map.size.width)
		{
			map.grid[y][x] = add_tile(data, map_data, x, y);
			++x;
		}
		++y;
	}
	return (map);
}

void	map_destroy(t_map *map)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < map->size.height)
	{
		x = 0;
		while (x < map->size.width)
		{
			tile_destroy(map->grid[y][x]);
			++x;
		}
		free(map->grid[y]);
		++y;
	}
	free(map->grid);
}
