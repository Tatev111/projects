#include "ft_printf.h"

int     work_with_flags(char *arr, int i, va_list arg, t_option *flags)  // save all info in struct
{
    while (arr[i])
    {
        if (arr[i] != '-' && arr[i] != '0' && arr[i] != '.' && arr[i] != '*' && !ft_isdigit(arr[i]) && !ft_istype(arr[i]))
            break;
        if (arr[i] == '0' && flags->flag_minus == 0 && flags->width == 0)
            flags->flag_zero = 1;
        if (arr[i] == '.')
            i = return_precision(arr, i, flags, arg);
        if (arr[i] == '-')
            *flags = ft_flagtype(*flags);
        if (arr[i] == '*')
            *flags = ft_get_arg(*flags, arg);
        if (ft_isdigit(arr[i]))
            *flags = ret_digit(*flags, arr[i]);
        if (ft_istype(arr[i]))
        {
            flags->type = arr[i];
            break;
        }
        i++;
    }
    return (i);
}


int     ft_treat_save(const char *save, va_list arg)
{
    int count;
    int i;
    t_option    init_flags;

    count = 0;
    i = 0;
    while (1)
    {
        init_flags = flag_initialize();
        if (!save[i])
            break;
        else if (save[i] == '%' && save[i + 1])
        {
            i = work_with_flags(save, ++i, arg, &init_flags);
            if (ft_istype(save[i]))
                count += start_printing(arg, init_flags);
            else if(save[i])
                count += fd_putchar(save[i]);
            //count += start_printing(arg, init_flags);
        }
        else if (save[i] != '%')
        {
            count += fd_putchar(save[i]);
        }
        i++;
    }
    return (count);
}

int     ft_printf(const char *input, ...)
{
    va_list     arg;
    const char  *save;
    int         count;

    count = 0;
    save = ft_strdup(input);
    va_start(arg, input);
    count += ft_treat_save(save, arg);
    va_end(arg);
    free((char *)save);
    return (count);
}