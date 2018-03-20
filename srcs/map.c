#include "fillit.h"

int		map_add_piece_isfree(t_map *map, t_piece *piece, int x, int y)
{
	int	i;

	i = 0;
	while (i < PIECE_MAX_LENGTH)
	{
		if (x + piece->coord[i].x >= map->size)
			return (FALSE);
		else if (y + piece->coord[i].y >= map->size)
			return (FALSE);
		else if (map->grid[y + piece->coord[i].y][x + piece->coord[i].x])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		map_add_piece_by_x(t_map *map, t_piece *piece, int x)
{
	int	y;
	int	i;

	i = -1;
	y = 0;
	while (y < map->size)
	{
		if (map_add_piece_isfree(map, piece, x, y) == TRUE)
		{
			while (++i < PIECE_MAX_LENGTH)
				map->grid[y + piece->coord[i].y][x + piece->coord[i].x] = piece;
			return (TRUE);
		}
		y++;
	}
	return (FALSE);
}

int		map_add_piece_by_y(t_map *map, t_piece *piece, int y)
{
	int	x;
	int	i;

	i = -1;
	x = 0;
	while (x < map->size)
	{
		if (map_add_piece_isfree(map, piece, x, y) == TRUE)
		{
			while (++i < PIECE_MAX_LENGTH)
				map->grid[y + piece->coord[i].y][x + piece->coord[i].x] = piece;
			return (TRUE);
		}
		x++;
	}
	return (FALSE);
}

int		map_remove_piece(t_map *map, t_piece *piece)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->grid[y][x] && map->grid[y][x]->id == piece->id)
				map->grid[y][x] = NULL;
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int		map_calc_size(t_map *map)
{
	int	size;
	int	x;
	int	y;

	y = 0;
	size = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->grid[y][x] != NULL && size - 1 < (x < y ? y : x))
				size = (x < y ? y : x) + 1;
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
