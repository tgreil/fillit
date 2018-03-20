#include "fillit.h"

int	ft_rec_place(t_fillit *fi, t_piece *piece, int pieces_placed)
{
	int		i_place;

	i_place = 0;
	while (i_place < fi->map.size)
	{
		piece->placed = TRUE;
		if (map_add_piece_by_x(&fi->map, piece, i_place))
			if (ft_rec(fi, pieces_placed + 1) == EXIT_FINISH)
				return (EXIT_FINISH);
		map_remove_piece(&fi->map, piece);
		piece->placed = FALSE;
		i_place++;
	}
	i_place = 0;
	while (i_place < fi->map.size)
	{
		piece->placed = TRUE;
		if (map_add_piece_by_y(&fi->map, piece, i_place))
			if (ft_rec(fi, pieces_placed + 1) == EXIT_FINISH)
				return (EXIT_FINISH);
		map_remove_piece(&fi->map, piece);
		piece->placed = FALSE;
		i_place++;
	}
	return (EXIT_SUCCESS);
}

int	ft_rec(t_fillit *fi, int pieces_placed)
{
	t_piece	*piece;
	int		i;

	i = 0;
	if (pieces_placed == fi->list_size)
		return (EXIT_FINISH);
	while (i < fi->list_size)
	{
		piece = pieces_get_byindex(fi->list, i);
		if (piece->placed == FALSE)
		{
			if (ft_rec_place(fi, piece, pieces_placed) == EXIT_FINISH)
				return (EXIT_FINISH);
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
	t_piece		p4;

	fi.list_size = 4;
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
	while (ft_rec(&fi, 0) != EXIT_FINISH)
		fi.map.size++;
	map_print(&fi.map, fi.to_color);
	return (0);
}
