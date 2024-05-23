/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:50:08 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 14:52:28 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_data.h>
#include <minimap.h>

int	get_map_line_number(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	special_keys(mlx_key_data_t keydata, void *par)
{
	t_gdata	*data;

	data = (t_gdata *)par;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		reset_dir(data);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		manage_map(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		data_destroy(data);
		mlx_close_window(data->mlx);
	}
}
