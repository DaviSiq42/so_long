/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:41:23 by davioliv          #+#    #+#             */
/*   Updated: 2023/05/04 11:23:55 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		a;
	char	*c;

	i = 0;
	a = 0;
	c = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !c)
		return (NULL);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		c[i + a] = s2[a];
		a++;
	}
	c[i + a] = '\0';
	return (c);
}

/*int	main(void)
{
	char	c[] = "ban";
	char	d[] = "ana";

	printf("%s", ft_strjoin(c, d));
	return (0);
}*/
