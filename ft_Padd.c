/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Padd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-h-m <oait-h-m@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:46:41 by oait-h-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:46:44 by oait-h-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padd(void *n)
{
	int	len;

	len = 0;
	len = len + ft_putstr("0x");
	len += ft_hexa((unsigned long)n, "0123456789abcdef");
	return (len);
}
