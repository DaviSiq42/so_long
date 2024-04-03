/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:10:50 by davioliv          #+#    #+#             */
/*   Updated: 2023/05/04 11:42:04 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	l;

	l = ft_strlen(dest);
	if (size > 0 && size > l)
	{
		i = l;
		a = 0;
		while (src[a] != '\0' && i + 1 < size)
		{
			dest[i] = src[a];
			i++;
			a++;
		}
		dest[i] = '\0';
		return (l + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
