#include  "ft_printf.h"

int ft_hexa(unsigned long n, char *hex)
{
	int count = 0;
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
