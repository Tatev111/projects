#include "ft_printf.h"

char     ft_istype(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (c);
    return (0);
}

int ft_part_in_write(t_option flags, char *s)
{
    int count;

    count = 0;
    if (flags.dot >= 0)
    {
        count += ft_write_flags(flags.dot, ft_strlen(s), 0);
        count += ft_write_arg(flags.dot, s);
    }
    else
    {
        count += ft_write_arg(ft_strlen(s), s);
    }
    return (count);
}

int string_write(t_option flags, char *s)
{
    int count;
    
    count = 0;
    if (!s)
        s = "(null)";
    if (flags.dot >= 0 && flags.dot > ft_strlen(s))
        flags.dot = ft_strlen(s);
    if (flags.flag_minus == 1)
        count += ft_part_in_write(flags, s);
    if (flags.dot >= 0)
        count += ft_write_flags(flags.width, flags.dot, 0);
    else
        count += ft_write_flags(flags.width, ft_strlen(s), 0);
    if (flags.flag_minus == 0)
        count += ft_part_in_write(flags, s);
    return (count);
}