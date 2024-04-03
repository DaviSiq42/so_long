/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:34 by davioliv          #+#    #+#             */
/*   Updated: 2023/06/15 14:25:14 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_subcount(char const *s, char c)
{
	size_t	w;

	w = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			w++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (w);
}

char	**ft_freets(char **sub, size_t i)
{
	while (sub[i] != NULL)
	{
		free(sub[i]);
		i--;
	}
	free(sub);
	return (NULL);
}

size_t	ft_getsize(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (*s != '\0' && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

char	*ft_putdelimiter(char **sub, char const *s, char c, size_t i)
{
	size_t	n;

	n = ft_subcount(s, c);
	sub[i] = ft_substr(s, 0, ft_getsize(s, c));
	if (!sub[i] && i < n)
	{
		ft_freets(sub, i);
		return (NULL);
	}
	return (sub[i]);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	size_t	i;
	char	**sub;	

	n = ft_subcount(s, c);
	i = 0;
	sub = malloc(sizeof(char *) * (n + 1));
	if (!s || !sub)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			ft_putdelimiter(sub, s, c, i);
			s = s + ft_getsize(s, c);
			i++;
		}
	}
	sub[i] = NULL;
	return (sub);
}
