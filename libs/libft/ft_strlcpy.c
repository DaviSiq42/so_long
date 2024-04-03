/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:09 by davioliv          #+#    #+#             */
/*   Updated: 2023/05/04 10:13:02 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (src[a] != '\0')
		a++;
	if (size == 0)
		return (a);
	else
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (a);
}

/*int	main(void)
{
	unsigned int	s;
	char	a[] = "setima";
	char	b[] = "";

	s = 7;
	printf("%i\n", ft_strlcpy(b, a, s));
	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
}*/
