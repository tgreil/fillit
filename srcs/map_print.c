#include "fillit.h"

void	map_print_putcolor(int color_index)
{
	if (color_index == 0)
		ft_putstr("\e[91m");
	else if (color_index == 1)
		ft_putstr("\e[92m");
	else if (color_index == 2)
		ft_putstr("\e[93m");
	else if (color_index == 3)
		ft_putstr("\e[94m");
	else if (color_index == 4)
		ft_putstr("\e[95m");
	else if (color_index == 5)
		ft_putstr("\e[96m");
	else if (color_index == 6)
		ft_putstr("\e[97m");
}

void	map_print_color(t_piece *piece)
{
	if (piece)
		map_print_putcolor(piece->type % COLOR_NB);
	else
		ft_putstr("\e[90m");
	ft_putchar('x');
	ft_putstr("\e[39m");
}

void	map_print_nocolor(t_piece *piece)
{
	if (piece)
		ft_putchar(piece->letter);
	else
		ft_putchar('.');
}

void	map_print(t_map *map, char to_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (to_color == TRUE)
				map_print_color(map->grid[x][y]);
			else
				map_print_nocolor(map->grid[x][y]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
