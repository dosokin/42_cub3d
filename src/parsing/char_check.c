/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:05:58 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 15:12:29 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_whitespace(char c)
{
	if (c >= 9 && c <= 13)
		return (true);
	if (c == 32)
		return (true);
	return (false);
}

bool	is_quote(char c)
{
	if (c == '\'')
		return (true);
	if (c == '\"')
		return (true);
	return (false);
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	is_sign(char c)
{
	if (c == '-')
		return (true);
	if (c == '+')
		return (true);
	return (false);
}

bool	is_invalid_map_char(char c, bool *found_player)
{
	if (c == ' ')
		return (0);
	if (c == '\n')
		return (0);
	if (c == '0' || c == '1')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*found_player)
		{
			error_manager(PLY_NBR);
			return (1);
		}
		*found_player = true;
		return (0);
	}
	return (1);
}
