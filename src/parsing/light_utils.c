/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:57:31 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 14:21:48 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <minimap.h>
#include <unistd.h>

void	increment_both(int *a, int *b)
{
	*a = *a + 1;
	*b = *b + 1;
}

bool	check_for_all_mandatory_files(void)
{
	int		i;
	char	*png_path;
	int		fd;

	i = 1;
	while (i <= 40)
	{
		png_path = ft_strjoin("./textures/player/", get_png(i));
		fd = open(png_path, O_RDONLY);
		free(png_path);
		if (fd < 0)
			return (false);
		close(fd);
		i++;
	}
	return (true);
}
