/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:59:05 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 15:33:21 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

bool	virus(char **spaced, int i, int j, char c)
{
	bool	executed;

	executed = false;
	if (spaced[i][j + 1] == c)
	{
		spaced[i][j + 1] = 'X';
		executed = true;
	}
	if (j > 0 && spaced[i][j - 1] == c)
	{
		spaced[i][j - 1] = 'X';
		executed = true;
	}
	if (spaced[i + 1] && spaced[i + 1][j] == c)
	{
		spaced[i + 1][j] = 'X';
		executed = true;
	}
	if (i > 0 && spaced[i - 1][j] == c)
	{
		spaced[i - 1][j] = 'X';
		executed = true;
	}
	return (executed);
}

bool	flood_map(char **spaced)
{
	int		i;
	int		j;
	bool	expanded;

	expanded = false;
	i = 0;
	while (spaced[i])
	{
		j = 0;
		while (spaced[i][j])
		{
			if (spaced[i][j] == 'X')
				if (virus(spaced, i, j, ' '))
					expanded = true;
			j++;
		}
		i++;
	}
	return (expanded);
}

bool	any_virused(char **flooded, int i, int j)
{
	if (virus(flooded, i, j, '0'))
		return (1);
	if (virus(flooded, i, j, 'N'))
		return (1);
	if (virus(flooded, i, j, 'E'))
		return (1);
	if (virus(flooded, i, j, 'S'))
		return (1);
	if (virus(flooded, i, j, 'W'))
		return (1);
	return (0);
}

int	check_flooded(char **flooded)
{
	int	i;
	int	j;

	i = 0;
	while (flooded[i])
	{
		j = 0;
		while (flooded[i][j])
		{
			if (flooded[i][j] == 'X' && any_virused(flooded, i, j))
				return (1);
			else if (flooded[i][j] == ' ')
				flooded[i][j] = '0';
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_spaced_map(char **spaced)
{
	int	i;
	int	j;

	spaced[0][0] = 'X';
	while (flood_map(spaced))
		;
	i = 0;
	while (spaced[i])
	{
		j = 0;
		while (spaced[i][j])
		{
			if (spaced[i][j] == ' ')
				spaced[i][j] = 'o';
			j++;
		}
		i++;
	}
	return (0);
}
