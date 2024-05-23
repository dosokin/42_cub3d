/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:54:12 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 14:55:25 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <defs.h>
#include <game_data.h>
#include <minimap.h>
#include <parsing.h>

void	pixel_settings(t_gdata *data)
{
	if (!data->minimap.is_bigmap)
	{
		data->minimap.pxl_square = (WIN_WIDTH / 4 / 10);
		if (data->minimap.pxl_square > (WIN_HEIGHT / 3 / 10))
			data->minimap.pxl_square = (WIN_HEIGHT / 3 / 10);
	}
	else
	{
		data->minimap.pxl_square = (((double)WIN_WIDTH * 0.95)
				/ (double)ft_strlen(data->assets.map[0]));
		if (data->minimap.pxl_square > (((double)WIN_HEIGHT * 0.95)
				/ (double)get_map_line_number(data->assets.map)))
			data->minimap.pxl_square = (((double)WIN_HEIGHT * 0.95)
					/ (double)get_map_line_number(data->assets.map));
	}
	data->minimap.pxl_player = data->minimap.pxl_square / 3;
	data->minimap.ratio = (double)(data->minimap.pxl_player)
		/ (double)(data->minimap.pxl_square);
}

void	draw_a_pxl_square(t_gdata *data, int rgb, int x, int y)
{
	int	i;
	int	j;
	int	tempo;

	i = 0;
	tempo = x;
	while (i < data->minimap.pxl_square)
	{
		j = 0;
		while (j < data->minimap.pxl_square)
		{
			mlx_put_pixel(data->minimap.bigmap.image, x, y, rgb);
			increment_both(&x, &j);
		}
		increment_both(&y, &i);
		x = tempo;
	}
}

void	recave_img(mlx_image_t *image, u_int32_t rgba, u_int32_t start_line)
{
	u_int32_t	x;
	u_int32_t	y;

	y = start_line;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, rgba);
			x++;
		}
		y++;
	}
}
