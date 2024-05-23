/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:38:01 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 15:34:29 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_data.h>
#include <stdlib.h>
#include <tile.h>

t_tile	*tile_new(t_tile_type type, t_gassets *assets)
{
	t_tile	*tile;

	tile = malloc(sizeof(t_tile));
	if (!tile)
		return (NULL);
	tile->type = type;
	tile->assets = assets;
	return (tile);
}

void	tile_destroy(t_tile *tile)
{
	if (!tile)
		return ;
	free(tile);
}
