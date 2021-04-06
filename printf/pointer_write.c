#include "ft_printf.h"

int     put_in_part_pointer_write(char *ptr, t_option flags)
{
    int count;

    count = 0;
    count += ft_write_arg(2, "0x");
    if (flags.dot >= 0)
    {
        count += ft_write_flags(flags.dot, ft_strlen(ptr), 1);
        count += ft_write_arg(flags.dot, ptr);
    }
    else
        count += ft_write_arg(ft_strlen(ptr), ptr);
    return (count);
}

int     pointer_write(t_option flags, unsigned long long ptr)
{
    char                *pointer;
    int                 count;
    unsigned long long  save_ptr;

    count = 0;
    save_ptr = ptr;
    if (save_ptr == 0 && flags.dot == 0)
    {
        count += ft_write_arg(2, "0x");
        return (count += ft_write_flags(flags.width, 0, 1));
    }
    pointer = ft_ull_base(save_ptr, 16);
    pointer = ft_str_lower(pointer);
    if (flags.dot < ft_strlen(pointer))
        flags.dot = ft_strlen(pointer);
    if (flags.flag_minus == 1)
        count += put_in_part_pointer_write(pointer, flags);
    count += ft_write_flags(flags.width, ft_strlen(pointer) + 2, 0);
    if (flags.flag_minus == 0)
        count += put_in_part_pointer_write(pointer, flags);
    free(pointer);
    return (count);
}
