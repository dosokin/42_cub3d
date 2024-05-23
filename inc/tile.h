/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:54 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:08:56 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

# include <defs.h>

typedef struct s_game_assets	t_gassets;

typedef struct s_tile
{
	t_tile_type					type;
	t_gassets					*assets;
}								t_tile;

t_tile							*tile_new(t_tile_type type, t_gassets *assets);
void							tile_destroy(t_tile *tile);

#endif
