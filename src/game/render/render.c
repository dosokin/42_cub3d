/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:02:51 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <casting.h>
#include <game.h>
#include <game_data.h>
#include <minimap.h>

void	render3d(t_gdata *data)
{
	int	cursor;

	cursor = 0;
	init_background(data->minimap.background.image, NULL);
	while (cursor < WIN_WIDTH)
		cursor_move(data, &cursor);
}
