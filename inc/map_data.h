/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:23 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:08:25 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DATA_H
# define MAP_DATA_H

# include <defs.h>
# include <tile.h>

typedef struct s_textures
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	int				rgb_f;
	int				rgb_c;
}					t_textures;

typedef struct s_player_dt
{
	double			x;
	double			y;
}					t_player_dt;

typedef struct s_direction_dt
{
	double			x;
	double			y;
}					t_direction_dt;

typedef struct s_map_data
{
	char			**map;
	t_textures		textures;
	t_player_dt		player;
	t_direction_dt	direction;
	t_size			size;
	char			*file;
	int				last_info_i;
}					t_map_data;

#endif
