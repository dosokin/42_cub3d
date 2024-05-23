/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:05:46 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/14 22:05:49 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_arg_cub(char *argument)
{
	int	length;

	if (!argument)
		return (false);
	length = ft_strlen(argument);
	if (length < 5)
		return (false);
	if (!ft_strcmp((argument + length - 4), ".cub"))
		return (true);
	return (false);
}
