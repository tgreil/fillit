#include "fillit.h"

int			ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int			ft_putchar(int c)
{
	return (write(1, &c, 1));
}
