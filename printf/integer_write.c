#include "ft_printf.h"

int		size_of_n(int n)
{
	int i;

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

char    *ft_itoa(int arg)
{
    char	*r;
	int		i;
	long	num;

	num = arg;
	i = size_of_n(num);
	if (!(r = (char *)malloc(i + 1)))
		return (NULL);
	r[i] = '\0';
	i--;
	if (num == 0)
		r[0] = '0';
	else if (num < 0)
	{
		r[0] = '-';
		num *= -1;
	}
	while (num != 0)
	{
		r[i] = (num % 10) + '0';
		num /= 10;
		--i;
	}
	return (r);
}

int     ft_part_in_itoa(t_option flags, char *str_num)
{
    int count;

    count = 0;
    if (flags.flag_minus == 1)
    {
        count += ft_write_flags(flags.dot, ft_strlen(str_num), 1);
        count += ft_write_arg(ft_strlen(str_num), str_num);
        if (flags.dot > ft_strlen(str_num))
            count += ft_write_flags(flags.width, flags.dot, 0);
        else
            count += ft_write_flags(flags.width, ft_strlen(str_num), 0);
    }
    else if (flags.flag_zero == 1)
    {
        if (flags.dot > ft_strlen(str_num))
            count += ft_write_flags(flags.width, flags.dot, 0);
        else
            count += ft_write_flags(flags.width, ft_strlen(str_num), 0);
        count += ft_write_flags(flags.dot, ft_strlen(str_num), 1);
        count += ft_write_arg(ft_strlen(str_num), str_num);     
    }
    return (count);
}

int     integer_write(t_option flags, int arg)
{
    int     count;
    char    *str_num;

    count = 0;
    str_num = (char *)malloc(size_of_n(arg) + 1);
    str_num = ft_itoa(arg);
    if (arg == 0 && flags.dot == 0)
        return (count += ft_write_flags(flags.width, 0, 0));
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