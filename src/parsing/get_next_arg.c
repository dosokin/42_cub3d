/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:41:33 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/14 22:42:10 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	find_next_quote(char *s, int *i)
{
	char	quote_type;
	int		length;

	length = 0;
	quote_type = s[*i];
	*i = *i + 1;
	while (s[*i] && s[*i] != quote_type)
		increment_both(i, &length);
	if (!s[*i])
		return (-1);
	if (s[*i] == quote_type)
		*i = *i + 1;
	return (length);
}

int	get_next_arg_length(char *s, int i, bool *quotes)
{
	int	length;
	int	tempo;

	length = 0;
	if (is_quote(s[i]))
	{
		tempo = i;
		length = find_next_quote(s, &i);
		if (length != -1)
		{
			*quotes = true;
			return (length);
		}
		i = tempo;
		length = 0;
	}
	while (s[i] && !is_whitespace(s[i]))
		increment_both(&i, &length);
	return (length);
}

char	*get_next_arg(char *s, int *i)
{
	char	*result;
	int		length;
	int		j;
	bool	quoted;

	quoted = false;
	length = get_next_arg_length(s, *i, &quoted);
	if (!length && !quoted)
		return (NULL);
	result = malloc((length + 1) * sizeof(char));
	j = 0;
	if (quoted && is_quote(s[*i]))
		*i = *i + 1;
	while (j < length)
	{
		result[j] = s[*i];
		increment_both(&j, i);
	}
	result[j] = 0;
	if (quoted)
		*i = *i + 1;
	return (result);
}
