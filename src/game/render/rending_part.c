/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rending_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:44:56 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:03:17 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <casting.h>
#include <defs.h>
#include <game.h>
#include <math.h>
#include <minimap.h>
#include <stddef.h>
#include <stdlib.h>

void	move_ray(double *ray, t_lr lr)
{
	static double	angle_step = FOV / WIN_WIDTH * DR;

	if (lr == RIGHT)
		*ray += angle_step;
	else if (lr == LEFT)
		*ray -= angle_step;
	if (*ray < 0)
		*ray = *ray + (2 * M_PI);
	else if (*ray > 2 * M_PI)
		*ray = *ray - (2 * M_PI);
}

int	find_extrem(t_gdata *data, t_lr lr, double *ray_angle, t_wall current)
{
	int			c;
	t_cast_res	res;

	c = 0;
	res = cast_ray_t_ignore(*ray_angle, data, &current);
	while (is_as_prev(&current, &res))
	{
		c++;
		move_ray(ray_angle, lr);
		res = cast_ray_t_ignore(*ray_angle, data, &current);
	}
	return (c);
}
