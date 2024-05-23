/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:44:00 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 14:49:57 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <defs.h>
#include <game_data.h>
#include <minimap.h>
#include <parsing.h>
#include <string.h>

int	get_colors(int x)
{
	static int	rgb_1 = -99;
	static int	rgb_2 = -99;

	if (rgb_1 == -99)
	{
		rgb_1 = get_rgba(255, 160, 122, 255);
		rgb_2 = get_rgba(152, 251, 152, 200);
	}
	if (x == 1)
		return (rgb_2);
	return (rgb_1);
}

void	put_the_pixel(t_gdata *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_pixel(data->minimap.minimap.image, x, y, get_colors(1));
	else if (c == '1')
		mlx_put_pixel(data->minimap.minimap.image, x, y, get_colors(2));
}

void	draw_a_map_square(t_gdata *data, int i)
{
	int		j;
	int		l;
	char	*s;

	j = 0;
	l = ft_strlen(data->assets.map[0]);
	s = data->assets.map[i];
	if (!s)
		return ;
	while (j < l)
	{
		if (s[j] == '0')
			draw_a_pxl_square(data, get_colors(1), j * data->minimap.pxl_square,
				i * data->minimap.pxl_square);
		else if (s[j] == '1')
			draw_a_pxl_square(data, get_colors(2), j * data->minimap.pxl_square,
				i * data->minimap.pxl_square);
		j++;
	}
}
