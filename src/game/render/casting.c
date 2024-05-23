/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:02:40 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <casting.h>
#include <game.h>
#include <game_data.h>
#include <math.h>

t_cast_res	cast_ray_up_t_ignore(double ray_angle, t_gdata *data,
		t_wall *target)
{
	t_cast_data	cd;
	int			i;

	cd = init_cast_data(data, UP, ray_angle);
	i = 0;
	while (i < (int)((data->map.size.height + data->map.size.width) * 3))
	{
		cd.map_y = (int32_t)map_fgrid_pos_t(cd.ry - 0.1);
		cd.map_x = (int32_t)map_fgrid_pos_t(cd.rx);
		++i;
		if (cd.map_x >= 0 && cd.map_x < (int32_t)data->map.size.width
			&& cd.map_y >= 0 && cd.map_y < (int32_t)data->map.size.height
			&& data->map.grid[cd.map_y][cd.map_x]->type == T_WALL)
			if (!target || touch_condition(target, cd.map_x, cd.map_y))
				return ((t_cast_res){.map_x = cd.map_x, .map_y = cd.map_y,
					.distance = get_distance(cd), .sd = SO});
		cd.rx += cd.offset_x;
		cd.ry += cd.offset_y;
		++i;
	}
	return ((t_cast_res){0});
}

t_cast_res	cast_ray_down_t_ignore(double ray_angle, t_gdata *data,
		t_wall *target)
{
	t_cast_data	cd;
	int			i;

	cd = init_cast_data(data, DOWN, ray_angle);
	i = 0;
	while (i < (int)((data->map.size.height + data->map.size.width) * 3))
	{
		cd.map_y = (int32_t)map_fgrid_pos_t(cd.ry + 0.1);
		cd.map_x = (int32_t)map_fgrid_pos_t(cd.rx);
		if (cd.map_x >= 0 && cd.map_x < (int32_t)data->map.size.width
			&& cd.map_y >= 0 && cd.map_y < (int32_t)data->map.size.height
			&& data->map.grid[cd.map_y][cd.map_x]->type == T_WALL)
			if (!target || touch_condition(target, cd.map_x, cd.map_y))
				return ((t_cast_res){.map_x = cd.map_x, .map_y = cd.map_y,
					.distance = get_distance(cd), .sd = NO});
		cd.rx += cd.offset_x;
		cd.ry += cd.offset_y;
		++i;
	}
	return ((t_cast_res){0});
}

t_cast_res	cast_ray_left_t_ignore(double ray_angle, t_gdata *data,
		t_wall *target)
{
	t_cast_data	cd;
	int			i;

	cd = init_cast_data(data, LT, ray_angle);
	i = 0;
	while (i < (int)((data->map.size.height + data->map.size.width) * 3))
	{
		cd.map_y = (int32_t)map_fgrid_pos_t(cd.ry);
		cd.map_x = (int32_t)map_fgrid_pos_t(cd.rx - 0.1);
		if (cd.map_x >= 0 && cd.map_x < (int32_t)data->map.size.width
			&& cd.map_y >= 0 && cd.map_y < (int32_t)data->map.size.height
			&& data->map.grid[cd.map_y][cd.map_x]->type == T_WALL)
			if (!target || touch_condition(target, cd.map_x, cd.map_y))
				return ((t_cast_res){.map_x = cd.map_x, .map_y = cd.map_y,
					.distance = get_distance(cd), .sd = EA});
		cd.rx += cd.offset_x;
		cd.ry += cd.offset_y;
		++i;
	}
	return ((t_cast_res){0});
}

t_cast_res	cast_ray_right_t_ignore(double ray_angle, t_gdata *data,
		t_wall *target)
{
	t_cast_data	cd;
	int			i;

	cd = init_cast_data(data, RT, ray_angle);
	i = 0;
	while (i < (int)((data->map.size.height + data->map.size.width) * 3))
	{
		cd.map_y = (int32_t)map_fgrid_pos_t(cd.ry);
		cd.map_x = (int32_t)map_fgrid_pos_t(cd.rx + 0.1);
		if (cd.map_x >= 0 && cd.map_x < (int32_t)data->map.size.width
			&& cd.map_y >= 0 && cd.map_y < (int32_t)data->map.size.height
			&& data->map.grid[cd.map_y][cd.map_x]->type == T_WALL)
			if (!target || touch_condition(target, cd.map_x, cd.map_y))
				return ((t_cast_res){.map_x = cd.map_x, .map_y = cd.map_y,
					.distance = get_distance(cd), .sd = WE});
		cd.rx += cd.offset_x;
		cd.ry += cd.offset_y;
		++i;
	}
	return ((t_cast_res){0});
}

t_cast_res	cast_ray_t_ignore(double ray_angle, t_gdata *data, t_wall *target)
{
	t_cast_res	h_res;
	t_cast_res	v_res;

	h_res = ((t_cast_res){0});
	v_res = ((t_cast_res){0});
	if (ray_angle > M_PI)
		h_res = cast_ray_up_t_ignore(ray_angle, data, target);
	else if (ray_angle < M_PI)
		h_res = cast_ray_down_t_ignore(ray_angle, data, target);
	if (ray_angle > PI_2 && ray_angle < PI_3)
		v_res = cast_ray_left_t_ignore(ray_angle, data, target);
	else if (ray_angle < PI_2 || ray_angle > PI_3)
		v_res = cast_ray_right_t_ignore(ray_angle, data, target);
	if (h_res.distance && v_res.distance)
	{
		if (h_res.distance < v_res.distance)
			return (h_res);
		return (v_res);
	}
	if (h_res.distance != 0)
		return (h_res);
	if (v_res.distance != 0)
		return (v_res);
	return ((t_cast_res){0});
}
