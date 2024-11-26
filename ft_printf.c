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

static int	ft_print_f(char sp, va_list list)
{
	int	count;

	count = 0;
	if (sp == 'd' || sp == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (sp == 'u')
		count += ft_putnbr(va_arg(list, unsigned int));
	else if (sp == 'x')
		count += ft_hexa(va_arg(list, unsigned int), "0123456789abcdef");
	else if (sp == 'X')
		count += ft_hexa(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (sp == 'p')
		count += ft_padd(va_arg(list, void *));
	else if (sp == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (sp == 'c')
		count += ft_putchar(va_arg(list, int));
	else
		count += ft_putchar(sp);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			count += ft_print_f(str[i], list);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
