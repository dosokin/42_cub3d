/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:52:40 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 14:54:01 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <game_data.h>
#include <keys.h>
#include <minimap.h>

t_cub_cor	init_cubcor(t_gdata *data, double x, double y)
{
	t_cub_cor	cor;
	double		ratio;

	ratio = data->minimap.ratio / (double)2;
	cor.supl_x = x - ratio;
	cor.supl_y = y - ratio;
	cor.supr_x = x + ratio;
	cor.supr_y = y - ratio;
	cor.infl_x = x - ratio;
	cor.infl_y = y + ratio;
	cor.infr_x = x + ratio;
	cor.infr_y = y + ratio;
	return (cor);
}

bool	is_position_walled(t_gdata *data, double new_pos_x, double new_pos_y)
{
	t_cub_cor	cor;

	cor = init_cubcor(data, new_pos_x, new_pos_y);
	if (data->assets.map[(int)(cor.supl_y / 1)][(int)(cor.supl_x / 1)] != '0')
		return (1);
	if (data->assets.map[(int)(cor.supr_y / 1)][(int)(cor.supr_x / 1)] != '0')
		return (1);
	if (data->assets.map[(int)(cor.infl_y / 1)][(int)(cor.infl_x / 1)] != '0')
		return (1);
	if (data->assets.map[(int)(cor.infr_y / 1)][(int)(cor.infr_x / 1)] != '0')
		return (1);
	return (0);
}
