#include "ft_printf.h"


int	ft_putnbr(long n)
{
    int i;

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