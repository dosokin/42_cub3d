/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:47:29 by msoubrou          #+#    #+#             */
/*   Updated: 2024/05/03 16:03:56 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_data.h>
#include <minimap.h>

void	init_background(mlx_image_t *image, t_map_data *map_data)
{
	static uint32_t	rgbc = -999;
	static uint32_t	rgbf = -999;

	if (map_data && rgbc == (uint32_t)-999)
	{
		rgbc = map_data->textures.rgb_c;
		rgbf = map_data->textures.rgb_f;
	}
	if (image)
	{
		recave_img(image, rgbc, 0);
		recave_img(image, rgbf, WIN_HEIGHT / 2);
	}
}

void	delete_cursor_textures(mlx_texture_t **tab, int *n)
{
	int	i;
	int	max;

	i = 0;
	max = 41;
	if (n)
		max = *n;
	while (i < max)
	{
		mlx_delete_texture(tab[i]);
		i++;
	}
}

bool	init_cursor_textures(t_gdata *data)
{
	int		i;
	char	*png_path;

	i = 0;
	while (i <= 40)
	{
		png_path = ft_strjoin("./textures/player/", get_png(i));
		data->minimap.cursor[i] = mlx_load_png(png_path);
		free(png_path);
		if (!data->minimap.cursor[i])
		{
			delete_cursor_textures(data->minimap.cursor, &i);
			return (false);
		}
		i++;
	}
	return (true);
}

int	init_wall_texture(t_gdata *data, t_img *img, char *path, int *loaded)
{
	img->texture = mlx_load_png(path);
	if (!img->texture)
		return (1);
	img->image = mlx_texture_to_image(data->mlx, img->texture);
	if (!mlx_resize_image(img->image, 100, 100))
		return (1);
	(*loaded)++;
	return (0);
}

int	delete_loaded(t_gdata *data, int loaded)
{
	if (!loaded)
		return (1);
	mlx_delete_image(data->mlx, data->assets.no.image);
	mlx_delete_texture(data->assets.no.texture);
	loaded--;
	if (!loaded)
		return (1);
	mlx_delete_image(data->mlx, data->assets.so.image);
	mlx_delete_texture(data->assets.so.texture);
	loaded--;
	if (!loaded)
		return (1);
	mlx_delete_image(data->mlx, data->assets.ea.image);
	mlx_delete_texture(data->assets.ea.texture);
	loaded--;
	if (!loaded)
		return (1);
	mlx_delete_image(data->mlx, data->assets.we.image);
	mlx_delete_texture(data->assets.we.texture);
	return (1);
}
