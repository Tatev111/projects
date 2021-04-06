#include "ft_printf.h"

char	*ft_print_hex_lowcase(unsigned int n)
{
	char	*hex;
	int		i;
	char	*res;

	i = 0;
	hex = "0123456789abcdef";
	if (!(res = (char *)malloc(size_of_un(n) + 1)))
		return (0);
    if (n <= 16)
    {
		res[i++] = hex[n % 16];
    }
    else
    {
        res[i++] = hex[n / 16];
	    res[i++] = hex[n % 16];
    }
	return (res);
}

char	*ft_print_hex_upcase(unsigned int n)
{
	int		i;
	char	*hex;
	char	*res;
	
	i = 0;
	hex = "0123456789ABCDEF";
	if (!(res = (char *)malloc(size_of_un(n) + 1)))
		return (0);
	if (n <= 16)
    {
		res[i++] = hex[n % 16];
    }
    else
    {
		res[i++] = hex[n / 16];	    
		res[i++] = hex[n % 16];
    }
	return (res);
}

int		hexa_write(t_option flags, unsigned int num, int is_lowcase)
{
	int count;
	char	*res;

	count = 0;

	if(is_lowcase)
		res = ft_print_hex_lowcase(num);
	else
		res = ft_print_hex_upcase(num);
	if (flags.flag_minus == 1 || flags.flag_zero == 1)
		count += ft_part_in_itoa(flags, res);
	else
	{
		if (flags.dot >= 0)
            count += ft_write_flags(flags.width, flags.dot, 0);
        else
            count += ft_write_flags(flags.width, ft_strlen(res), 0);
        count += ft_write_flags(flags.dot, ft_strlen(res), 1);
        count += ft_write_arg(ft_strlen(res), res);
	}
	free(res);
	return (count);
}