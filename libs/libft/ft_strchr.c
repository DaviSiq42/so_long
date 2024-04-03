/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:24:56 by davioliv          #+#    #+#             */
/*   Updated: 2023/06/06 14:30:57 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}

/*int	main(void)
{
	const char	*s = "vesto";
	int	c = 'e';

	printf("%s", ft_strchr(s, c));
	return (0);
}*/
