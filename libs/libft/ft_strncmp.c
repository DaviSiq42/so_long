/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:32:13 by davioliv          #+#    #+#             */
/*   Updated: 2023/05/04 10:13:30 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0' && c < n)
		c++;
	if (c == n)
		return (0);
	else
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}

/*int	main(void)
{
	const char *s1 = "test\200";
	const char *s2 = "test\0";

	printf("%i\n", ft_strncmp(s1, s2, 6));
	printf("%i\n", strncmp(s1, s2, 6));
	return (0);
}*/
