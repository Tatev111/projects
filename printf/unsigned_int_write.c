#include "ft_printf.h"

int		size_of_un(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char    *ft_u_itoa(unsigned int num)
{
    char *str_num;
    int len;

    len = size_of_un(num);
    if (!(str_num = (char *)malloc(len + 1)))
            return (0);
    str_num[len] = '\0';
    while (num != 0)
    {
        str_num[len - 1] = (num % 10) + '0';
        len--;
        num /= 10;
    }
    return(str_num);
}

int     unsigned_int_write(t_option flags, unsigned int num)
{
    int count;
    char *str_num;

    count = 0;
    num = (unsigned int)(4294967296 + num);
    if (num == 0 && flags.dot == 0)
        return (count += ft_write_flags(flags.width, 0, 0));
    str_num = ft_u_itoa(num);
    if (flags.flag_minus == 1 || flags.flag_zero == 1)
        count += ft_part_in_itoa(flags, str_num);
    else
    {
        if (flags.dot >= 0)
            count += ft_write_flags(flags.width, flags.dot, 0);
        else
            count += ft_write_flags(flags.width, ft_strlen(str_num), 0);
        count += ft_write_flags(flags.dot, ft_strlen(str_num), 1);
        count += ft_write_arg(ft_strlen(str_num), str_num);
    }
    free(str_num);
    return (count);
}