#include "fillit.h"

void	map_print_color(t_piece *piece)
{

}

void	map_print_nocolor(t_piece *piece)
{
	if (piece)
		ft_putchar(piece->letter);
	else
		ft_putchar('.'):
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
