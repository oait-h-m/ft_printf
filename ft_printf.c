/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:23 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:47:24 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_f(char format, va_list list)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_putchar('%');
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (format == 'u')
		count += ft_putnbr(va_arg(list, unsigned int));
	else if (format == 'x')
		count += ft_hexa(va_arg(list, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		count += ft_hexa(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		count += ft_padd(va_arg(list, void *));
	else if (format == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (format == 'c')
		count += ft_putchar(va_arg(list, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (!str || write(1, 0, 0) == -1)
		return (-1);
	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_print_f(str[i], list);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
