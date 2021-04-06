#include "ft_printf.h"

int     char_write(t_option flags, char c)
{
    int count;

    count = 0;
    if (flags.flag_minus == 1)
        count += fd_putchar(c);
    count += ft_write_flags(flags.width, 1, 0);
    if (flags.flag_minus == 0)
        count += fd_putchar(c);
    return (count);
}