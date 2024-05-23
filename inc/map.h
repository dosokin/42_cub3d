/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:31 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:08:33 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <defs.h>
# include <map_data.h>

typedef struct s_game_data	t_gdata;

typedef struct s_map
{
	t_size					size;
	uint32_t				grid_size;
	t_tile					***grid;
}							t_map;

double						map_fgrid_pos(t_map *map, double pos);
t_map						map_new(t_gdata *data, t_map_data *map_data);
void						map_destroy(t_map *map);

#endif
