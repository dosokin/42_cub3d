/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:58:04 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 14:21:30 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_data.h"
#include "parsing.h"
#include <string.h>

int	player_char(char c, t_map_data *map)
{
	if (c == 'N')
		map->direction.y = 1;
	else if (c == 'S')
		map->direction.y = -1;
	else if (c == 'W')
		map->direction.x = -1;
	else if (c == 'E')
		map->direction.x = 1;
	else
		return (0);
	return (1);
}

void	get_player_data(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (player_char(map->map[i][j], map))
			{
				map->map[i][j] = '0';
				map->player.x = (double)j + 0.5;
				map->player.y = (double)i + 0.5;
				return ;
			}
			++j;
		}
		map->size.width = j;
		++i;
	}
}

void	init_map_data(t_map_data *map)
{
	map->direction.x = 0;
	map->direction.y = 0;
	map->size.height = map->size.height + 2;
	get_player_data(map);
}

int	scraping_main(int argc, char **argv, t_map_data *map)
{
	if (!check_for_all_mandatory_files())
	{
		error_manager(MISSING_FILES);
		return (1);
	}
	if (argc != 2 || !is_arg_cub(argv[1]))
	{
		error_manager(INV_ARG);
		return (1);
	}
	if (bober_parse(argv[1], map))
		return (1);
	if (map_manager(map))
		return (1);
	init_map_data(map);
	return (0);
}
