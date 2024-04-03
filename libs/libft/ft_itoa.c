/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:28:53 by davioliv          #+#    #+#             */
/*   Updated: 2023/06/15 14:25:58 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lenitoa(long n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n >= 10)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long	rn;
	int		l;
	char	*c;

	rn = n;
	l = ft_lenitoa(rn);
	c = malloc(sizeof(char) * (l + 1));
	if (!c)
		return (NULL);
	c[l--] = '\0';
	if (rn < 0)
	{
		rn *= -1;
		c[0] = '-';
	}
	if (rn == 0)
		c[0] = '0';
	while (rn > 0)
	{
		c[l--] = rn % 10 + '0';
		rn /= 10;
	}
	return (c);
}

/*int main()
{
	printf("ran %s\n", ft_itoa(-0));

	printf("min %s\n", ft_itoa(-2147483648));
	printf("max %s\n", ft_itoa(2147483647));
	return (0);

}*/
