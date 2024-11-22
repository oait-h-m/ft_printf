/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:18 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:46:21 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long n, char *hex)
{
	int	count;

	count = 0;
	if (n < 16)
	{
		count += write(1, &hex[n], 1);
	}
	else
	{
		count += ft_hexa(n / 16, hex);
		count += write(1, &hex[n % 16], 1);
	}
	return (count);
}
