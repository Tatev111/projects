#include "ft_printf.h"

char *ft_ull_base_write(unsigned long long ull, int base, char *ptr, int count)
{
    while (ull != 0)
    {
        if ((ull % base) < 10)
            ptr[count - 1] = (ull % base) + 48;
        else
            ptr[count - 1] = (ull % base) + 55;
        ull /= base;
        count--;
    }
    return (ptr);
}

char    *ft_ull_base(unsigned long long ull, int base)
{
    char                *pointer;
    unsigned long long  save_ull;
    int                 count;

    count = 0;
    save_ull = ull;
    if (save_ull == 0)
        return (ft_strdup("0"));
    while (save_ull != 0)
    {
        save_ull /= base;
        count++;
    }
    if (!(pointer = malloc(sizeof(char) * (count + 1))))
        return (0);
    pointer[count] = '\0';
    pointer = ft_ull_base_write(save_ull, base, pointer, count);
    return (pointer);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char    *ft_str_lower(char *str)
{
    int i;
    
    i = 0;
    while (str)
    {
        str[i] = ft_tolower(str[i]);
        str++;
    }
    return (str);
}