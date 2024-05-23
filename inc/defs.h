/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:06:50 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:06:53 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define WIN_WIDTH 1300
# define WIN_HEIGHT 700

# define FOV 90.0
# define SPEED 25

# include <bits/stdint-uintn.h>
# include <stdlib.h>

typedef enum e_tile_type
{
	T_VOID,
	T_WALL,
	T_FLOOR
}				t_tile_type;

typedef struct s_size
{
	uint32_t	width;
	uint32_t	height;
}				t_size;

int				get_rgba(int r, int g, int b, int a);

#endif
