/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:06:40 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:06:44 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# include <game.h>

bool		touch_condition(t_wall *target, int map_x, int map_y);
t_cast_data	init_up_down(t_gdata *data, t_dir dir, double ray_angle);
t_cast_data	init_lt_rt(t_gdata *data, t_dir dir, double ray_angle);
t_cast_data	init_cast_data(t_gdata *data, t_dir dir, double ray_angle);
double		get_distance(t_cast_data cd);
void		cursor_move(t_gdata *data, int *cursor);
double		map_fgrid_pos_t(double pos);
t_wall		init_wall_info(t_cast_res res);
t_cast_res	cast_ray_t_ignore(double ray_angle, t_gdata *data, t_wall *target);
bool		is_as_prev(t_wall *prev, t_cast_res *res);
void		move_ray(double *ray, t_lr lr);
int			find_extrem(t_gdata *data, t_lr lr, double *ray_angle,
				t_wall current);

#endif
