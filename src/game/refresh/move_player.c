/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:02:20 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>
#include <game_data.h>
#include <minimap.h>

void	rotation_keys(t_gdata *data, int addition)
{
	manage_angle(data, addition);
	put_player(data);
	data->render = true;
}

void	game_loop(void *param)
{
	t_gdata	*data;

	data = (t_gdata *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		(w_move(data));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		(s_move(data));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		(a_move(data));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		(d_move(data));
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotation_keys(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotation_keys(data, -1);
	if (data->render)
	{
		if (data->minimap.is_bigmap)
			manage_map(data);
		render_game(data);
		data->render = false;
	}
}
