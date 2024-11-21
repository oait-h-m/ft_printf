#include "ft_printf.h"

int ft_Padd(void *n)
{
    int len;

    len = 0;
    len = len + ft_putstr("0x");
    len += ft_hexa((unsigned long)n, "0123456789abcdef");
    return (len);
}