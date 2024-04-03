/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:27:08 by davioliv          #+#    #+#             */
/*   Updated: 2023/05/04 11:28:47 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (nd[j] == '\0')
		return ((char *)hs);
	while (hs[i] != '\0')
	{
		while (hs[i + j] == nd[j] && hs[i + j] != '\0' && i + j < len)
			j++;
		if (nd[j] == '\0')
			return ((char *)hs + i);
		i++;
		j = 0;
	}
	return (0);
}
