/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:12:57 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 19:55:46 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

int	lp_to_data(t_lp *lp, t_map_data *data)
{
	data->last_info_i = 0;
	data->size.height = 0;
	data->textures.no = extract("NO", lp, &data->last_info_i);
	if (!data->textures.no)
		return (error_manager(MISS_INFO));
	data->textures.so = extract("SO", lp, &data->last_info_i);
	if (!data->textures.so)
		return (error_manager(MISS_INFO));
	data->textures.ea = extract("EA", lp, &data->last_info_i);
	if (!data->textures.ea)
		return (error_manager(MISS_INFO));
	data->textures.we = extract("WE", lp, &data->last_info_i);
	if (!data->textures.we)
		return (error_manager(MISS_INFO));
	if (extract_rgb("F", lp, &data->textures.rgb_f, &data->last_info_i))
		return (error_manager(MISS_INFO));
	if (extract_rgb("C", lp, &data->textures.rgb_c, &data->last_info_i))
		return (error_manager(MISS_INFO));
	return (0);
}

t_lp	*create_a_lp(char *s, int *i, t_lp *last)
{
	t_lp	*lp;
	char	*value;

	value = get_next_arg(s, i);
	if (!value)
		return (NULL);
	lp = malloc(sizeof(t_lp));
	lp->value = value;
	lp->end_i = *i;
	lp->next = NULL;
	if (last)
		last->next = lp;
	return (lp);
}

t_lp	*init_lps(char *s)
{
	t_lp	*first;
	t_lp	*current;
	t_lp	*tempo;
	int		i;

	first = NULL;
	current = NULL;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i]))
			i++;
		if (s[i])
		{
			tempo = create_a_lp(s, &i, current);
			if (tempo)
				current = tempo;
		}
		if (!first)
			first = current;
	}
	return (first);
}

char	*ft_strdupi(char *to_copy, int l)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((l + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < l)
	{
		result[i] = to_copy[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

int	bober_parse(char *file_name, t_map_data *map_data)
{
	t_lp	*lp;
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		r;

	if (test_the_file(file_name))
		return (1);
	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		return (error_manager(OP_MAPFILE));
	r = read(fd, buffer, BUFFER_SIZE);
	close(fd);
	if (r < 0)
		return (1);
	map_data->file = ft_strdupi(buffer, r);
	if (!map_data->file)
		return (1);
	lp = init_lps(map_data->file);
	if (lp_to_data(lp, map_data))
		return (deinit_lps(lp));
	deinit_lps(lp);
	if (check_xpm(map_data))
		return (error_manager(INV_XPM));
	return (0);
}
