/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:07:44 by davioliv          #+#    #+#             */
/*   Updated: 2023/04/17 15:00:31 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *)str)[a] = c;
		a++;
	}
	return (str);
}

/*int	main(void)
{
	char c[] = "     teste";
	ft_memset(c, 57, 5);
	puts(c);
	return (0);
}*/
