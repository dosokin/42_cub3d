/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:09 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 15:41:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H

# include <MLX42.h>
# include <defs.h>
# include <map.h>
# include <map_data.h>
# include <stdbool.h>

typedef struct s_img
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}					t_img;

typedef struct s_minimap_data
{
	t_img			background;
	t_img			minimap_back;
	t_img			minimap;
	t_img			bigmap;
	t_img			player_on_map;
	mlx_texture_t	*cursor[41];
	int				pxl_square;
	int				pxl_player;
	double			ratio;
	bool			is_bigmap;
}					t_minimap;

typedef struct s_game_assets
{
	char			**map;
	t_img			no;
	t_img			we;
	t_img			so;
	t_img			ea;
}					t_gassets;

typedef struct s_player
{
	double			position_x;
	double			position_y;
	double			direction_x;
	double			direction_y;
	double			angle;
}					t_player;

typedef enum e_side
{
	NO,
	WE,
	SO,
	EA
}					t_side;

typedef struct s_game_data
{
	void			*mlx;
	t_player		player;
	t_gassets		assets;
	t_minimap		minimap;
	t_map			map;
	bool			render;
}					t_gdata;

void				data_destroy(t_gdata *data);
void				clear_mapdata(t_map_data *map_data);

bool				dispatch_data(t_gdata *data, t_map_data *map_data);
bool				game_data_init(t_gdata *data, t_map_data *map_data);
void				delete_cursor_textures(mlx_texture_t **tab, int *n);

int					init_wall_texture(t_gdata *data, t_img *img, char *path,
						int *loaded);
int					delete_loaded(t_gdata *data, int loaded);

#endif
