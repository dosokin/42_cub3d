/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:49 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 13:25:26 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_data.h>
#include <math.h>

int	reset_dir(t_gdata *data)
{
	static double	direction_x_tempo = -1;
	static double	direction_y_tempo = -1;
	static double	angle_tempo = -1;

	if (direction_x_tempo == -1)
	{
		direction_x_tempo = data->player.direction_x;
		direction_y_tempo = data->player.direction_y;
		angle_tempo = data->player.angle;
		return (1);
	}
	data->player.direction_x = direction_x_tempo;
	data->player.direction_y = direction_y_tempo;
	data->player.angle = angle_tempo;
	return (0);
}

void	manage_angle(t_gdata *data, int addition)
{
	data->player.angle -= (double)addition * (0.025 * M_PI);
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	if (data->player.angle < 0)
		data->player.angle = 2 * M_PI + data->player.angle;
	data->player.direction_x = cos(data->player.angle);
	data->player.direction_y = -sin(data->player.angle);
}
