/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:12:57 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 18:56:23 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

void	set_rgb(t_lp *lp, int *rgb, int *last_info, int extr[])
{
	*rgb = get_rgba(extr[0], extr[1], extr[2], 255);
	if (lp->end_i > *last_info)
		*last_info = lp->end_i;
}

int	extract_ints(t_lp *lp, int *rgb, int *last_info, int i)
{
	int	k;
	int	extr[3];

	k = 0;
	while (k < 3)
	{
		while (is_whitespace(lp->value[i]) || lp->value[i] == ',')
			i++;
		if (!lp->value[i])
		{
			lp = lp->next;
			i = 0;
			if (!lp)
				return (1);
			continue ;
		}
		extr[k] = ft_atoi(lp->value, &i);
		if (extr[k] == -999)
			return (1);
		k++;
	}
	set_rgb(lp, rgb, last_info, extr);
	return (0);
}

int	extract_rgb(char *to_find, t_lp *lp, int *rgb, int *last_info)
{
	while (lp->next)
	{
		if (!ft_strcmp(to_find, lp->value))
		{
			lp = lp->next;
			if (extract_ints(lp, rgb, last_info, 0))
			{
				error_manager(RGB_ERR);
				return (1);
			}
			return (0);
		}
		lp = lp->next;
	}
	return (1);
}

char	*extract(char *to_find, t_lp *lp, int *last_info)
{
	char	*result;

	result = NULL;
	while (lp && lp->next)
	{
		if (!ft_strcmp(to_find, lp->value))
		{
			if (result)
			{
				if (ft_strcmp(result, lp->next->value))
				{
					error_manager(MIS_INFOS);
					free(result);
					return (NULL);
				}
			}
			lp = lp->next;
			result = ft_strdup(lp->value);
			if (*last_info < lp->end_i)
				*last_info = lp->end_i;
		}
		lp = lp->next;
	}
	return (result);
}
