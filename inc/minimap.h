/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:38 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 14:20:36 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <game_data.h>

void	put_player(t_gdata *data);

void	init_minimap(t_gdata *data);
void	init_bigmap(t_gdata *data);
void	init_background(mlx_image_t *image, t_map_data *map_data);
bool	init_cursor_textures(t_gdata *data);
void	manage_map(t_gdata *data);

void	manage_angle(t_gdata *data, int addition);
int		reset_dir(t_gdata *data);
void	manage_angle(t_gdata *data, int addition);

bool	is_position_walled(t_gdata *data, double new_pos_x, double new_pos_y);
void	special_keys(mlx_key_data_t keydata, void *par);

int		a_move(t_gdata *data);
int		s_move(t_gdata *data);
int		w_move(t_gdata *data);
int		d_move(t_gdata *data);

char	*ft_strjoin(char *a, char *b);
int		get_map_line_number(char **s);

void	pixel_settings(t_gdata *data);
void	draw_a_pxl_square(t_gdata *data, int rgb, int x, int y);
void	recave_img(mlx_image_t *image, u_int32_t rgba, u_int32_t start_line);

int		get_colors(int x);
void	put_the_pixel(t_gdata *data, char c, int x, int y);
void	draw_a_map_square(t_gdata *data, int i);

char	*get_png(int i);

#endif
