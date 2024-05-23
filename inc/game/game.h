/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:01 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:08:03 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define PI_2 1.570796
# define PI_3 4.712388
# define DR 0.0174533
# define GRID_SIZE 64

# include <game_data.h>

typedef struct s_cast_res
{
	double	map_x;
	double	map_y;
	double	distance;
	t_side	sd;
}			t_cast_res;

typedef struct s_wall_infos
{
	double	map_x;
	double	map_y;
	t_side	sd;
}			t_wall;

typedef struct s_cast_data
{
	double	py;
	double	px;
	double	rx;
	double	ry;
	double	dtx;
	double	dty;
	double	offset_x;
	double	offset_y;
	double	atan;
	double	ntan;
	int32_t	map_x;
	int32_t	map_y;
}			t_cast_data;

typedef enum e_dir
{
	UP,
	DOWN,
	RT,
	LT,
}			t_dir;

typedef enum e_left_right
{
	LEFT,
	RIGHT,
}			t_lr;

typedef struct s_texturing_data
{
	double	h_step;
	double	v_step;
	int		h_offset;
	int		screen_adapted_size;
}			t_texturing;

void		game_loop(void *param);
int			window_clear(t_gdata *data);
double		ft_abs(double n);
void		render_game(t_gdata *data);
void		render3d(t_gdata *data);

#endif
