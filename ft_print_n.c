/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:00 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:47:06 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		i++;
	}
	if (n > 9)
	{
		i = i + ft_putnbr((n / 10));
		i = i + ft_putchar((n % 10) + '0');
	}
	else
		return (i + ft_putchar(n + '0'));
	return (i);
}
