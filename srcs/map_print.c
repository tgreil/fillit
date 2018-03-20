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


int main() {
	t_piece		pieces[2];
	t_map		map;

	pieces[0].letter = 'A';
	pieces[0].type = 0;
	pieces[1].letter = 'B';
	pieces[1].type = 1;
	map_create(&map, 4);
	map.grid[0][0] = &(pieces[0]);
	map.grid[0][1] = &(pieces[0]);
	map.grid[0][2] = &(pieces[0]);
	map.grid[0][3] = &(pieces[0]);
	map.grid[2][1] = &(pieces[1]);
	map.grid[2][2] = &(pieces[1]);
	map.grid[1][1] = &(pieces[1]);
	map.grid[1][2] = &(pieces[1]);
	map_print(&map, FALSE);
	map_print(&map, TRUE);
	return (0);
}
