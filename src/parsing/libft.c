/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:42:34 by dosokin           #+#    #+#             */
/*   Updated: 2024/04/14 22:57:04 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (b[i])
		return (b[i]);
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

int	ft_atoi(char *s, int *i)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	if (s[*i])
	{
		if (preliminary_ops(s, i, &c))
			return (-999);
		while (is_num(s[*i]))
		{
			r = (r * 10) + (s[*i] - '0');
			c++;
			if (c > 5)
				return (-999);
			*i = *i + 1;
		}
		if (r > 255 || c == 0)
			return (-999);
		return (r);
	}
	return (-999);
}

char	*ft_strjoin(char *a, char *b)
{
	int		i;
	int		j;
	char	*r;
	int		l;

	l = ft_strlen(a) + ft_strlen(b);
	r = malloc((l + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (a[i])
	{
		r[j] = a[i];
		increment_both(&i, &j);
	}
	i = 0;
	while (b[i])
	{
		r[j] = b[i];
		increment_both(&i, &j);
	}
	r[j] = 0;
	return (r);
}
