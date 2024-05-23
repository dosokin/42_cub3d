/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/05/03 15:42:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <defs.h>
#include <error.h>
#include <game.h>
#include <game_data.h>
#include <math.h>
#include <minimap.h>
#include <stdbool.h>

bool	init_minimap_data(t_gdata *data, t_map_data *map_data)
{
	data->minimap.background.image = mlx_new_image(data->mlx, WIN_WIDTH,
			WIN_HEIGHT);
	if (!data->minimap.background.image)
		return (false);
	init_background(data->minimap.background.image, map_data);
	data->minimap.minimap.image = NULL;
	data->minimap.is_bigmap = false;
	data->minimap.player_on_map.texture = NULL;
	pixel_settings(data);
	return (true);
}

int	init_assets_data(t_gdata *data, t_map_data *map_data)
{
	int	loaded;

	loaded = 0;
	if (init_wall_texture(data, &data->assets.no, map_data->textures.no,
			&loaded))
		return (delete_loaded(data, loaded));
	if (init_wall_texture(data, &data->assets.so, map_data->textures.so,
			&loaded))
		return (delete_loaded(data, loaded));
	if (init_wall_texture(data, &data->assets.ea, map_data->textures.ea,
			&loaded))
		return (delete_loaded(data, loaded));
	if (init_wall_texture(data, &data->assets.we, map_data->textures.we,
			&loaded))
		return (delete_loaded(data, loaded));
	data->assets.map = map_data->map;
	return (0);
}

void	init_player_data(t_gdata *data, t_map_data *map_data)
{
	data->player.position_x = map_data->player.x;
	data->player.position_y = map_data->player.y;
	data->player.direction_x = map_data->direction.x;
	data->player.direction_y = map_data->direction.y;
	if (data->player.direction_x)
		data->player.angle = atan2(data->player.direction_y,
				data->player.direction_x);
	else
		data->player.angle = M_PI + atan2(data->player.direction_y,
				data->player.direction_x);
}

bool	dispatch_data(t_gdata *data, t_map_data *map_data)
{
	if (!init_cursor_textures(data))
		return (false);
	if (init_assets_data(data, map_data))
	{
		delete_cursor_textures(data->minimap.cursor, NULL);
		return (false);
	}
	if (!init_minimap_data(data, map_data))
		return (false);
	init_player_data(data, map_data);
	return (true);
}

bool	game_data_init(t_gdata *data, t_map_data *map_data)
{
	*data = (t_gdata){0};
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "BOBER", false);
	if (!data->mlx)
	{
		error_manager_exec(MLX_INIT);
		return (false);
	}
	if (!dispatch_data(data, map_data))
		return (false);
	if (window_clear(data))
		return (false);
	data->map = map_new(data, map_data);
	if (!data->map.grid)
		return (false);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_key_hook(data->mlx, special_keys, data);
	render_game(data);
	init_minimap(data);
	put_player(data);
	return (true);
}
