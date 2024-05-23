/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:21:16 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <game.h>
#include <game_data.h>
#include <math.h>
#include <minimap.h>

double	map_fgrid_pos_t(double pos)
{
	return (floor(pos / GRID_SIZE));
}

t_wall	init_wall_info(t_cast_res res)
{
	t_wall	wall;

	wall.map_x = res.map_x;
	wall.map_y = res.map_y;
	wall.sd = res.sd;
	return (wall);
}

bool	is_as_prev(t_wall *prev, t_cast_res *res)
{
	if (res->map_x == prev->map_x && res->map_y == prev->map_y
		&& res->sd == prev->sd)
		return (true);
	return (false);
}

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
