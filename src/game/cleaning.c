/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/05/03 14:18:21 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_data.h>
#include <stdbool.h>

void	data_destroy(t_gdata *data)
{
	static bool	cleaned = false;

	if (!cleaned)
	{
		if (data->minimap.is_bigmap)
			mlx_delete_image(data->mlx, data->minimap.bigmap.image);
		else
			mlx_delete_image(data->mlx, data->minimap.minimap.image);
		mlx_delete_image(data->mlx, data->minimap.background.image);
		mlx_delete_texture(data->assets.no.texture);
		mlx_delete_image(data->mlx, data->assets.no.image);
		mlx_delete_texture(data->assets.so.texture);
		mlx_delete_image(data->mlx, data->assets.so.image);
		mlx_delete_texture(data->assets.ea.texture);
		mlx_delete_image(data->mlx, data->assets.ea.image);
		mlx_delete_texture(data->assets.we.texture);
		mlx_delete_image(data->mlx, data->assets.we.image);
		delete_cursor_textures(data->minimap.cursor, NULL);
		cleaned = !cleaned;
	}
}

void	clear_mapdata(t_map_data *map_data)
{
	int	i;

	if (map_data->textures.no)
		free(map_data->textures.no);
	if (map_data->textures.so)
		free(map_data->textures.so);
	if (map_data->textures.ea)
		free(map_data->textures.ea);
	if (map_data->textures.we)
		free(map_data->textures.we);
	if (map_data->file)
		free(map_data->file);
	if (map_data->map)
	{
		i = 0;
		while (map_data->map[i])
			free(map_data->map[i++]);
		free(map_data->map);
	}
}
