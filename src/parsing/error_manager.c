/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:36:58 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 15:12:16 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	error_manager(t_error type)
{
	static bool	errored = false;
	char		*error_message;
	const char	*error[] = {"Invalid arguments\n",
		"Unable to open the specified file\n", "File is empty\n",
		"Invalid given map informations\n",
		"Non existent or misplaced map\n", "Duplicated map infos\n",
		"Allocation issue\n", "Invalid informations\n",
		"Invalid RGB infos\n", "Mismatched infos\n", "Missing map infos\n",
		"Map has to be surrounded by walls\n",
		"Invalid character in the map\n", "Invalid number of player\n",
		"The player is missing\n", "Invalid map\n",
		"Textures are not png\n", "Error opening png file\n",
		"Error opening map file\n", "Missing mandatory files\n"};

	if (!errored)
	{
		error_message = (char *)error[type];
		write(2, "Error\n", 6);
		write(2, error_message, ft_strlen(error_message));
		errored = !errored;
	}
	return (1);
}
