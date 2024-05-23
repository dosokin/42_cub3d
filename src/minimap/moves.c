/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:51:43 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 14:52:18 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "error.h"
#include "game_data.h"
#include <game.h>
#include <math.h>
#include <minimap.h>

void	render_game(t_gdata *data)
{
	render3d(data);
	init_minimap(data);
}

int	w_move(t_gdata *data)
{
	double	new_x;
	double	new_y;
	int		try;

	try = 1;
	new_x = data->player.position_x + (data->player.direction_x * SPEED / 1000);
	new_y = data->player.position_y - (data->player.direction_y * SPEED / 1000);
	while (is_position_walled(data, new_x, new_y) && try < 10)
	{
		new_x = data->player.position_x + (data->player.direction_x * SPEED
				/ 1000 * pow(0.75, try));
		new_y = data->player.position_y - (data->player.direction_y * SPEED
				/ 1000 * pow(0.75, try));
		try++;
	}
	if (try == 10)
		return (1);
	data->player.position_y = new_y;
	data->player.position_x = new_x;
	data->render = true;
	return (0);
}

int	d_move(t_gdata *data)
{
	int	z;

	z = 20;
	manage_angle(data, -z);
	w_move(data);
	manage_angle(data, z);
	return (0);
}

int	s_move(t_gdata *data)
{
	double	new_x;
	double	new_y;
	int		try;

	try = 0;
	new_x = data->player.position_x - (data->player.direction_x * SPEED / 1000);
	new_y = data->player.position_y + (data->player.direction_y * SPEED / 1000);
	while (is_position_walled(data, new_x, new_y) && try < 10)
	{
		new_x = data->player.position_x - (data->player.direction_x * SPEED
				/ 1000 * pow(0.75, try));
		new_y = data->player.position_y + (data->player.direction_y * SPEED
				/ 1000 * pow(0.75, try));
		try++;
	}
	if (try == 10)
		return (1);
	data->player.position_y = new_y;
	data->player.position_x = new_x;
	data->render = true;
	return (0);
}

int	a_move(t_gdata *data)
{
	int	z;

	z = 20;
	manage_angle(data, z);
	w_move(data);
	manage_angle(data, -z);
	return (0);
}
