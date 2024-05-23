/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/05/03 15:42:16 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <MLX42.h>
#include <game.h>
#include <game_data.h>
#include <map.h>
#include <minimap.h>
#include <stdlib.h>

void	clean_exit(t_gdata *data, t_map_data *map_data)
{
	data_destroy(data);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	map_destroy(&data->map);
	clear_mapdata(map_data);
}

int	main(int ac, char **av)
{
	t_gdata		data;
	t_map_data	map_data;

	map_data = ((t_map_data){0});
	if (scraping_main(ac, av, &map_data))
	{
		clear_mapdata(&map_data);
		return (EXIT_FAILURE);
	}
	if (!game_data_init(&data, &map_data))
	{
		mlx_close_window(data.mlx);
		mlx_terminate(data.mlx);
		clear_mapdata(&map_data);
		return (EXIT_FAILURE);
	}
	mlx_loop(data.mlx);
	clean_exit(&data, &map_data);
	return (EXIT_SUCCESS);
}
