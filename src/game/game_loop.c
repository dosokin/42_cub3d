/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:35:45 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 12:58:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>
#include <game_data.h>
#include <math.h>

double	radiant_to_degree(double angle)
{
	return (angle * 180 / M_PI);
}

uint32_t	grid_pos(t_gdata *data, double pos)
{
	return ((uint32_t)floor(pos / data->map.grid_size));
}
