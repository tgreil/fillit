#include "fillit.h"

void		ft_tabtab_cpy(t_piece ***dest, t_piece ***src, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			dest[y][x] = src[y][x];
			x++;
		}
		y++;
	}
}

int			ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (EXIT_SUCCESS);
}

int			ft_putchar(int c)
{
	return (write(1, &c, 1));
}
