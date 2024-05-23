/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 13:22:53 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <game_data.h>
#include <stdio.h>

int	window_clear(t_gdata *data)
{
	if (mlx_image_to_window(data->mlx, data->minimap.background.image, 0, 0)
		== -1)
		return (1);
	return (0);
}
