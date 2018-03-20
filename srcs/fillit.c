#include "fillit.h"

int	fillit_stock_result(t_map *map, t_map *result)
{
	int	act_size;

	act_size = map_calc_size(map);
	if (act_size < result->size)
	{
		result->size = act_size;
		ft_tabtab_cpy(result->grid, map->grid, act_size);
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
		map_print(&fi->map, TRUE);
		ft_putchar('\n');
		if (pieces_get_byindex(fi->list, i)->placed == FALSE)
		{
			pieces_get_byindex(fi->list, i)->placed = TRUE;
			if (map_add_piece(&fi->map, pieces_get_byindex(fi->list , i)))
				ft_rec(fi, pieces_placed + 1);
			map_remove_piece(&fi->map, pieces_get_byindex(fi->list , i));
			pieces_get_byindex(fi->list, i)->placed = FALSE;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int main()
{
	t_fillit	fi;
	t_piece		p1;
	t_piece		p2;
	t_piece		p3;

	fi.list_size = 3;
	fi.to_color = TRUE;

	p1.id = 0;
	p1.type = 0;
	p1.coord[0].x = 0;
	p1.coord[0].y = 0;
	p1.coord[1].x = 1;
	p1.coord[1].y = 0;
	p1.coord[2].x = 0;
	p1.coord[2].y = 1;
	p1.coord[3].x = 2;
	p1.coord[3].y = 0;
	p1.placed = FALSE;
	p1.next = &p2;

	p2.id = 1;
	p2.type = 1;
	p2.coord[0].x = 0;
	p2.coord[0].y = 0;
	p2.coord[1].x = 1;
	p2.coord[1].y = 1;
	p2.coord[2].x = 0;
	p2.coord[2].y = 1;
	p2.coord[3].x = 1;
	p2.coord[3].y = 0;
	p2.placed = FALSE;
	p2.next = &p3;

	p3.id = 2;
	p3.type = 2;
	p3.coord[0].x = 0;
	p3.coord[0].y = 0;
	p3.coord[1].x = 1;
	p3.coord[1].y = 1;
	p3.coord[2].x = 0;
	p3.coord[2].y = 1;
	p3.coord[3].x = 1;
	p3.coord[3].y = 0;
	p3.placed = FALSE;
	p3.next = NULL;

	fi.list = &p1;
	map_create(&fi.map, fi.list_size * PIECE_MAX_LENGTH);
	fi.map.size = 1;
	while (fi.map.size * fi.map.size < fi.list_size * PIECE_MAX_LENGTH)
		fi.map.size++;

	map_create(&fi.result, fi.list_size * PIECE_MAX_LENGTH);
	ft_rec(&fi, 0);
	map_print(&fi.result, fi.to_color);
	return (0);
}
