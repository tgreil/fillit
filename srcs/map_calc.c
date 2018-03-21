#include "fillit.h"

int		map_calc_minsize(t_map *map, int list_size)
{
	int	min;

	min = 1;
	while (min * min < list_size * PIECE_MAX_LENGTH)
		min++;
	map->size = min;
	return (min);
}
