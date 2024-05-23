/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:44:00 by msoubrou          #+#    #+#             */
/*   Updated: 2024/05/03 14:09:53 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <defs.h>
#include <game_data.h>
#include <minimap.h>
#include <parsing.h>
#include <string.h>

void	create_minimap(t_gdata *data, int map_size)
{
	data->minimap.minimap.image = mlx_new_image(data->mlx, map_size, map_size);
	data->minimap.minimap_back.image = mlx_new_image(data->mlx,
			(u_int32_t)(map_size * 1.1), (u_int32_t)(map_size * 1.1));
	recave_img(data->minimap.minimap_back.image, get_rgba(255, 255, 255, 100),
		0);
	mlx_image_to_window(data->mlx, data->minimap.minimap_back.image, WIN_HEIGHT
		* 0.02, WIN_HEIGHT * 0.02);
	mlx_image_to_window(data->mlx, data->minimap.minimap.image, WIN_HEIGHT
		* 0.02 + map_size * 0.05, WIN_HEIGHT * 0.02 + map_size * 0.05);
}

void	init_minimap(t_gdata *data)
{
	int		i;
	int		j;
	double	x;
	double	y;

	if (!data->minimap.minimap.image)
		create_minimap(data, data->minimap.pxl_square * 10);
	recave_img(data->minimap.minimap.image, get_rgba(255, 255, 255, 0), 0);
	y = data->player.position_y - 5.0;
	i = -1;
	while (++i < data->minimap.pxl_square * 10)
	{
		if (y >= 0 && y < get_map_line_number(data->assets.map))
		{
			x = data->player.position_x - 5.0;
			j = -1;
			while (++j < data->minimap.pxl_square * 10)
			{
				if (x >= 0 && x < ft_strlen(data->assets.map[0]))
					put_the_pixel(data, data->assets.map[(int)y][(int)x], j, i);
				x += 1 / ((double)data->minimap.pxl_square * 10.0 / 10);
			}
		}
		y += 1 / ((double)data->minimap.pxl_square * 10.0 / 10);
	}
}

void	init_bigmap(t_gdata *data)
{
	int	i;
	int	x;
	int	y;

	x = ((WIN_WIDTH) - (ft_strlen(data->assets.map[0])
				* data->minimap.pxl_square)) / 2;
	y = ((WIN_HEIGHT) - (get_map_line_number(data->assets.map)
				* data->minimap.pxl_square)) / 2;
	data->minimap.minimap_back.image = mlx_new_image(data->mlx, WIN_WIDTH
			- (WIN_HEIGHT * 0.04), WIN_HEIGHT * 0.96);
	recave_img(data->minimap.minimap_back.image, get_rgba(255, 255, 255, 100),
		0);
	mlx_image_to_window(data->mlx, data->minimap.minimap_back.image, WIN_HEIGHT
		* 0.02, WIN_HEIGHT * 0.02);
	data->minimap.bigmap.image = mlx_new_image(data->mlx,
			ft_strlen(data->assets.map[0]) * data->minimap.pxl_square,
			get_map_line_number(data->assets.map) * data->minimap.pxl_square);
	mlx_image_to_window(data->mlx, data->minimap.bigmap.image, x, y);
	i = -1;
	while (++i < get_map_line_number(data->assets.map))
		draw_a_map_square(data, i);
	put_player(data);
}

void	manage_map(t_gdata *data)
{
	data->minimap.is_bigmap = !data->minimap.is_bigmap;
	pixel_settings(data);
	if (data->minimap.is_bigmap)
	{
		mlx_delete_image(data->mlx, data->minimap.minimap_back.image);
		data->minimap.minimap_back.image = NULL;
		data->minimap.player_on_map.texture = NULL;
		mlx_delete_image(data->mlx, data->minimap.player_on_map.image);
		data->minimap.player_on_map.image = NULL;
		mlx_delete_image(data->mlx, data->minimap.minimap.image);
		data->minimap.minimap.image = NULL;
		init_bigmap(data);
		return ;
	}
	mlx_delete_image(data->mlx, data->minimap.minimap_back.image);
	data->minimap.minimap_back.image = NULL;
	data->minimap.player_on_map.texture = NULL;
	mlx_delete_image(data->mlx, data->minimap.player_on_map.image);
	data->minimap.player_on_map.image = NULL;
	mlx_delete_image(data->mlx, data->minimap.bigmap.image);
	data->minimap.bigmap.image = NULL;
	init_minimap(data);
	put_player(data);
}
