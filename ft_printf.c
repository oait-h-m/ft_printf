#include "ft_printf.h"

static int ft_print_f(char format, va_list list)
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
                count += ft_Padd(va_arg(list, void *));
            else if (format == 's')
                count += ft_putstr(va_arg(list, char *));
            else if (format == 'c')
                count += ft_putchar(va_arg(list, int));
	return (count);
}
int ft_printf(const char *str, ...)
{
  va_list list;
  va_start(list, str);
  int i = 0;
  int count = 0;
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
/*
int main() {
    char d = 'a';
    int a = ft_printf("%x \n", -214);
    printf("-----------\n");
    int b = printf("%x \n", -214);
    ft_printf("ft_printf count: %d, printf count: %d\n", a, b);

    return 0;
}

int main()
{
  char d = 'a';
  int a = ft_printf(" %p \n",&d );
  printf("-----------\n");
  int b = printf(" %p \n",&d);
  ft_printf("%d %d", a, b);

}
        if (str[i] == '%')
        {
			i++;
            if (str[i] == '%')
                count += ft_putchar('%');
            else if (str[i] == 'd' || str[i] == 'i')
                count += ft_putnbr(va_arg(list, int));
            else if (str[i] == 'u')
                count += ft_putnbr(va_arg(list, unsigned int));
            else if (str[i] == 'x')
                count += ft_hexa(va_arg(list, unsigned int), "0123456789abcdef");
            else if (str[i] == 'X')
                count += ft_hexa(va_arg(list, unsigned int), "0123456789ABCDEF");
            else if (str[i] == 'p')
                count += ft_Padd(va_arg(list, void *));
            else if (str[i] == 's')
                count += ft_putstr(va_arg(list, char *));
            else if (str[i] == 'c')
                count += ft_putchar(va_arg(list, int));
        }
        else
             count += ft_putchar(str[i]);
*/
