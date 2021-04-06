#include "ft_printf.h"

t_option    flag_initialize(void)
{
    t_option flags;
	
    flags.flag_minus = 0;
    flags.flag_zero = 0;
    flags.dot = -1;
    flags.star = 0;
    flags.width = 0;
    flags.type = 0;

    return (flags);
}

char	*ft_strdup(const char *str)
{
	char	*helper;
	int	s_size;
	int	i;

	i = 0;
	s_size = ft_strlen(str) + 1;
	if (!str)
		return (0);
	if (!(helper = (char*)malloc(s_size * sizeof(char))))
		return (0);
	while (i < s_size)
	{
		helper[i] = str[i];
		++i;
	}
	helper[i] = '\0';
	return (helper);
}

int	ft_strlen(const char *str)
{
	int size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

t_option    ft_flagtype(t_option f)
{
    f.flag_minus = 1;
    f.flag_zero = 0;

    return (f);
}