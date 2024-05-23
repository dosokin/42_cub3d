/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:21:03 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <casting.h>
#include <game.h>
#include <game_data.h>
#include <math.h>

bool	touch_condition(t_wall *target, int map_x, int map_y)
{
	if (target->sd == SO)
	{
		if (map_y <= target->map_y)
			return (true);
	}
	else if (target->sd == NO)
	{
		if (map_y >= target->map_y)
			return (true);
	}
	else if (target->sd == WE)
	{
		if (map_x >= target->map_x)
			return (true);
	}
	else if (target->sd == EA)
	{
		if (map_x <= target->map_x)
			return (true);
	}
	return (false);
}

t_cast_data	init_up_down(t_gdata *data, t_dir dir, double ray_angle)
{
	t_cast_data	cast;

	cast.py = data->player.position_y * 64.0;
	cast.px = data->player.position_x * 64.0;
	cast.atan = -1 / tan(ray_angle);
	if (dir == UP)
	{
		cast.dty = cast.py - (map_fgrid_pos_t(cast.py - 1) * GRID_SIZE);
		cast.offset_y = -GRID_SIZE;
	}
	else
	{
		cast.dty = (map_fgrid_pos_t(cast.py) + 1) * GRID_SIZE - cast.py;
		cast.offset_y = GRID_SIZE;
	}
	cast.dtx = cast.dty / tan(ray_angle);
	cast.offset_x = -cast.offset_y * cast.atan;
	return (cast);
}

t_cast_data	init_lt_rt(t_gdata *data, t_dir dir, double ray_angle)
{
	t_cast_data	cast;

	cast.py = data->player.position_y * 64.0;
	cast.px = data->player.position_x * 64.0;
	cast.ntan = -tan(ray_angle);
	if (dir == RT)
	{
		cast.dtx = (map_fgrid_pos_t(cast.px) + 1) * GRID_SIZE - cast.px;
		cast.offset_x = GRID_SIZE;
	}
	else
	{
		cast.offset_x = -GRID_SIZE;
		cast.dtx = cast.px - (map_fgrid_pos_t(cast.px)) * GRID_SIZE;
	}
	cast.dty = cast.dtx * tan(ray_angle);
	cast.offset_y = -cast.offset_x * cast.ntan;
	return (cast);
}

t_cast_data	init_cast_data(t_gdata *data, t_dir dir, double ray_angle)
{
	t_cast_data	cast;

	if (dir == UP || dir == DOWN)
		cast = init_up_down(data, dir, ray_angle);
	else if (dir == RT || dir == LT)
		cast = init_lt_rt(data, dir, ray_angle);
	if (dir == UP || dir == LT)
	{
		cast.rx = cast.px - cast.dtx;
		cast.ry = cast.py - cast.dty;
	}
	else if (dir == DOWN || dir == RT)
	{
		cast.rx = cast.px + cast.dtx;
		cast.ry = cast.py + cast.dty;
	}
	return (cast);
}

double	get_distance(t_cast_data cd)
{
	return (sqrt(pow(ft_abs(cd.px - cd.rx), 2) + pow(ft_abs(cd.py - cd.ry),
				2)));
}
