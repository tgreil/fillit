#include "fillit.h"

int	fillit_stock_result(t_map *map, t_map *result)
{
	int	act_size;

	act_size = map_calc_size(map);
	if (act_size < result->size)
	{
		result->size = act_size;
		ft_tabtab_cpy(result->grid, map->grid, map->size);
	}
	return (EXIT_SUCCESS);
}

int	ft_rec(t_fillit *fi, int pieces_placed)
{
	int		i;

	i = 0;
	if (pieces_placed == fi->list_size)
		return (fillit_stock_result(&fi->map, &fi->result));
	while (i < fi->list_size)
	{
		if (pieces_get_byindex(fi->list , i)->placed == FALSE)
		{
			pieces_get_byindex(fi->list , i)->placed = TRUE;
			map_place_piece(fi->map, pieces_get_byindex(fi->list , i));
			ft_rec(fi, pieces_placed + 1);
			pieces_get_byindex(fi->list , i)->placed = FALSE;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int main()
{

	return (0);
}
