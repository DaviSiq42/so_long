/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:34 by davioliv          #+#    #+#             */
/*   Updated: 2024/03/05 17:55:55 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*sub;

	l = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > l)
		return (ft_strdup(""));
	if (l - start < len)
		len = l - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

/*int	main(void)
{
	const char *c = "antagonista";

	printf("%s", ft_substr(c, 5, 7));
	return (0);
}*/	
