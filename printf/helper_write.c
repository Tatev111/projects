#include "ft_printf.h"

int     ft_write_arg(int flag, char *s)
{
    int count;

    count = 0;
    while (s[count] && count < flag)
        fd_putchar(s[count++]);
    return (count);
}

int     ft_write_flags(int width, int minus, int has_zero)
{
    int count;

    count = 0;
    while (width - minus > 0)
    {
        if (has_zero) 
            count += fd_putchar('0');
        else
            count += fd_putchar(' ');
        width--;
    }
    return (count);
}


