/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:01:16 by davioliv          #+#    #+#             */
/*   Updated: 2023/06/05 12:31:23 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_insert(size_t e, size_t b, char *c, const char *s1)
{
	size_t	i;

	i = 0;
	while (e > b)
	{
		c[i] = s1[b];
		b++;
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	b;
	size_t	e;
	char	*c;

	e = ft_strlen(s1);
	b = 0;
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	while (s1[b] != '\0' && ft_check(s1[b], set) == 1)
		b++;
	while (b < e && ft_check(s1[e - 1], set) == 1)
		e--;
	c = malloc(sizeof(char) * (e - b + 1));
	if (!c)
		return (NULL);
	return (ft_insert(e, b, c, s1));
}

/*int	main(void)
{
	const char	*s1 = "teste de fidelidade";
	const char	*set = "ted";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
