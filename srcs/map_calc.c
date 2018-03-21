#include "fillit.h"

int		map_calc_minsize(t_map *map, int list_size)
{
	map->size += list_size - list_size;
	return (4);
}
