/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:51:37 by davioliv          #+#    #+#             */
/*   Updated: 2024/03/05 17:56:17 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(const char type, va_list args)
{
	int	final_len;

	final_len = 0;
	if (type == 'c')
		final_len += ft_printchar(va_arg(args, int));
	else if (type == 's')
		final_len += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		final_len += ft_printptr(va_arg(args, unsigned long));
	else if (type == 'd' || type == 'i')
		final_len += ft_printnbr(va_arg(args, int));
	else if (type == 'u')
		final_len += ft_printunbr(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		final_len += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		final_len += ft_printpercent();
	return (final_len);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, type);
	while (type[i])
	{
		if (type[i] == '%')
		{
			len += ft_type(type[i + 1], args);
			i++;
		}
		else
			len += ft_printchar(type[i]);
		i++;
	}
	va_end(args);
	return (len);
}
