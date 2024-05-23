/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:55:46 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 14:18:06 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <defs.h>
#include <game_data.h>
#include <math.h>
#include <minimap.h>
#include <parsing.h>
#include <stdlib.h>

char	*get_png(int i)
{
	static const char	*png[] = {
		"40.png", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png",
		"8.png", "9.png", "10.png", "11.png", "12.png", "13.png", "14.png",
		"15.png", "16.png", "17.png", "18.png", "19.png", "20.png",
		"21.png", "22.png", "23.png", "24.png", "25.png", "26.png",
		"27.png", "28.png", "29.png", "30.png", "31.png", "32.png",
		"33.png", "34.png", "35.png", "36.png", "37.png", "38.png",
		"39.png", "40.png",
	};

	return ((char *)png[i]);
}

void	set_coordonates(t_gdata *data, int *x, int *y)
{
	if (!data->minimap.is_bigmap)
	{
		*x = (5.0 * (double)data->minimap.pxl_square) + WIN_HEIGHT * 0.02
			+ (data->minimap.pxl_square * 10) * 0.05 - (data->minimap.pxl_square
				/ 2);
		*y = *x;
	}
	else
	{
		*x = ((WIN_WIDTH) - (ft_strlen(data->assets.map[0])
					* data->minimap.pxl_square)) / 2;
		*y = ((WIN_HEIGHT) - (get_map_line_number(data->assets.map)
					* data->minimap.pxl_square)) / 2;
		*x += data->player.position_x * data->minimap.pxl_square;
		*y += data->player.position_y * data->minimap.pxl_square;
		*x -= data->minimap.pxl_square / 2;
		*y -= data->minimap.pxl_square / 2;
	}
}

void	load_png(t_gdata *data, int i)
{
	if (data->minimap.player_on_map.texture)
		data->minimap.player_on_map.texture = NULL;
	if (data->minimap.player_on_map.image)
	{
		mlx_delete_image(data->mlx, data->minimap.player_on_map.image);
		data->minimap.player_on_map.image = NULL;
	}
	data->minimap.player_on_map.texture = data->minimap.cursor[i];
}

void	put_player(t_gdata *data)
{
	int				i;
	static double	tempo_angle = -999;
	int				x;
	int				y;

	set_coordonates(data, &x, &y);
	if (data->player.angle != tempo_angle || !data->minimap.player_on_map.image)
	{
		tempo_angle = data->player.angle;
		i = 40 - (int)(data->player.angle / (M_PI / 20));
		load_png(data, i);
		data->minimap.player_on_map.image = mlx_texture_to_image(data->mlx,
				data->minimap.player_on_map.texture);
		mlx_resize_image(data->minimap.player_on_map.image,
			data->minimap.pxl_square, data->minimap.pxl_square);
		mlx_image_to_window(data->mlx, data->minimap.player_on_map.image, x, y);
	}
}
