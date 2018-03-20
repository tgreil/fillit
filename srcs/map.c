#include "fillit.h"

int		map_calc_size(t_map *map)
{
	int	size;
	int	x;
	int	y;

	x = 0;
	y = 0;
	size = 0;
	while (y < map->size)
	{
		while (x < map->size)
		{
			if (map->grid[y][x] != NULL && size < (x < y ? y : x))
				size = (x < y ? y : x);
			x++;
		}
		y++;
	}
	return (size);
}

int		map_create(t_map *map, int size)
{
	int	i_y;
	int	i_x;

	i_y = 0;
	map->size = size;
	if (!(map->grid = malloc(sizeof(t_piece **) * size)))
		return (EXIT_ERROR);
	while (i_y < size)
	{
		if (!(map->grid[i_y] = malloc(sizeof(t_piece *) * size)))
			return (EXIT_ERROR);
		i_x = 0;
		while (i_x < size)
		{
			map->grid[i_y][i_x] = NULL;
			i_x++;
		}
		i_y++;
	}
	return (EXIT_SUCCESS);
}
