/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:12:57 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 19:55:27 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <parsing.h>

int	get_rgba(int x, int r, int g, int b)
{
	return (x << 24 | r << 16 | g << 8 | b);
}

int	test_the_file(char *file_name)
{
	char	buffer[1];
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (error_manager(INV_FILE));
	if (read(fd, buffer, 1) < 1)
	{
		close(fd);
		return (error_manager(EMPTY_FILE));
	}
	close(fd);
	return (0);
}

int	check_extension(char *s)
{
	int	fd;

	if (ft_strlen(s) < 4)
		return (1);
	if (ft_strcmp((s + ft_strlen(s) - 4), ".png"))
		return (1);
	fd = open(s, O_RDONLY);
	if (fd <= 0)
	{
		error_manager(ERR_OP_XPM);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_xpm(t_map_data *data)
{
	if (check_extension(data->textures.no))
		return (1);
	if (check_extension(data->textures.so))
		return (1);
	if (check_extension(data->textures.ea))
		return (1);
	if (check_extension(data->textures.we))
		return (1);
	return (0);
}
