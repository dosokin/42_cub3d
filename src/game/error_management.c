/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <msoubrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:44:42 by msoubrou          #+#    #+#             */
/*   Updated: 2024/04/15 12:57:17 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <game_data.h>
#include <stdbool.h>
#include <unistd.h>

static int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	error_manager_exec(t_err err_type)
{
	static bool			returned = false;
	static const char	*error[] = {"MLX issue: unable to create an image\n",
		"MLX issue: unable to input image to window\n",
		"MLX issue: unable to init connection\n"};

	if (!returned)
	{
		write(2, "Error\n", 6);
		write(2, error[err_type], ft_strlen((char *)error[err_type]));
		returned = !returned;
	}
	return (1);
}
