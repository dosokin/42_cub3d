/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:44:56 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:11:38 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "minimap.h"
#include <casting.h>
#include <defs.h>
#include <game.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

int	*get_wall_width(t_gdata *data, double ray_angle, t_wall current)
{
	int	*wall_dimension;

	wall_dimension = malloc(2 * sizeof(int));
	move_ray(&ray_angle, LEFT);
	wall_dimension[0] = find_extrem(data, LEFT, &ray_angle, current);
	move_ray(&ray_angle, RIGHT);
	wall_dimension[1] = find_extrem(data, RIGHT, &ray_angle, current);
	if (!wall_dimension[1])
		wall_dimension[1] = 1;
	return (wall_dimension);
}

int	*init_pixels(t_gdata *data, t_cast_res *current)
{
	int	*pixels;

	if (current->sd == NO)
		pixels = (int *)data->assets.no.image->pixels;
	else if (current->sd == SO)
		pixels = (int *)data->assets.so.image->pixels;
	else if (current->sd == EA)
		pixels = (int *)data->assets.ea.image->pixels;
	else
		pixels = (int *)data->assets.we.image->pixels;
	return (pixels);
}

t_texturing	define_steping(t_cast_res *res, int *wall_dimension)
{
	int			og_size;
	t_texturing	texturing;

	og_size = (WIN_HEIGHT * GRID_SIZE) / res->distance;
	if (og_size > WIN_HEIGHT)
	{
		texturing.screen_adapted_size = WIN_HEIGHT;
		texturing.h_offset = (og_size - WIN_HEIGHT) / 2;
	}
	else
	{
		texturing.h_offset = 0;
		texturing.screen_adapted_size = og_size;
	}
	if (!og_size)
		og_size = 1;
	texturing.h_step = 100.0 / og_size;
	texturing.v_step = 100.0 / wall_dimension[1];
	return (texturing);
}

void	print_vertical_line(t_gdata *data, int cursor, t_cast_res *res,
		int *wall_dimension)
{
	int			i;
	int			y;
	t_texturing	texturing;
	int			*pixels;

	i = -1;
	pixels = init_pixels(data, res);
	texturing = define_steping(res, wall_dimension);
	y = (WIN_HEIGHT / 2) - (texturing.screen_adapted_size / 2);
	while (++i < texturing.screen_adapted_size)
	{
		mlx_put_pixel(data->minimap.background.image, cursor, y + i,
			pixels[(int)((i + texturing.h_offset) * texturing.h_step)*100
			+ (int)(wall_dimension[0] * texturing.v_step)]);
	}
}

void	cursor_move(t_gdata *data, int *cursor)
{
	t_cast_res		res;
	static double	ray_angle;
	int				*wall_dimension;
	static t_wall	current;

	if (!*cursor)
	{
		ray_angle = data->player.angle - DR * (FOV / 2);
		move_ray(&ray_angle, 5);
	}
	res = cast_ray_t_ignore(ray_angle, data, NULL);
	current = init_wall_info(res);
	wall_dimension = get_wall_width(data, ray_angle, current);
	while (*cursor < WIN_WIDTH && is_as_prev(&current, &res))
	{
		print_vertical_line(data, *cursor, &res, wall_dimension);
		wall_dimension[0]++;
		(*cursor)++;
		move_ray(&ray_angle, RIGHT);
		res = cast_ray_t_ignore(ray_angle, data, NULL);
	}
	free(wall_dimension);
}
