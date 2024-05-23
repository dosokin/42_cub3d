/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:36:43 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/15 18:02:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	deinit_lps(t_lp *lp)
{
	t_lp	*current;

	if (lp)
	{
		while (lp->next)
		{
			current = lp;
			free(lp->value);
			lp = lp->next;
			free(current);
		}
		free(lp->value);
		free(lp);
	}
	return (1);
}

int	preliminary_ops(char *s, int *i, int *c)
{
	if (!is_num(s[*i]) && !is_sign(s[*i]))
		return (-999);
	if (is_sign(s[*i]))
		if (s[*i] == '-')
			return (-999);
	while (s[*i] == '0')
	{
		*c = 1;
		*i = *i + 1;
	}
	return (0);
}
