/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:52:16 by davioliv          #+#    #+#             */
/*   Updated: 2024/03/05 17:56:32 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex(unsigned int a, const char format)
{
	int	len;

	len = 0;
	if (a >= 16)
	{
		ft_printhex(a / 16, format);
		ft_printhex(a % 16, format);
		len++;
	}
	else
	{
		if (a <= 9)
			ft_putchar_fd(a + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(a - 10 + 'a', 1);
			else
				ft_putchar_fd(a - 10 + 'A', 1);
		}
	}
	return (len);
}

int	ft_printhex(unsigned int a, const char format)
{
	return (ft_hex(a, format));
}
