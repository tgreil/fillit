#include "fillit.h"

int	ft_rec_place(t_fillit *fi, t_piece *piece, int pieces_placed)
{
	int	x;
	int y;

	y = 0;
	while (y < fi->map.size)
	{
		x = 0;
		while (x < fi->map.size)
		{
			if (map_add_piece(&fi->map, piece, x, y) == TRUE)
			{
				piece->placed = TRUE;
				if (ft_rec(fi, pieces_placed + 1) == EXIT_FINISH)
					return (EXIT_FINISH);
				map_remove_piece(&fi->map, piece);
				piece->placed = FALSE;
			}
			x++;
		}
		y++;
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
	t_piece		p[8];

	fi.list_size = 8;
	fi.to_color = TRUE;

	p[0].id = 0;
	p[0].type = 0;
	p[0].coord[0].x = 0;
	p[0].coord[0].y = 0;
	p[0].coord[1].x = 0;
	p[0].coord[1].y = 1;
	p[0].coord[2].x = 0;
	p[0].coord[2].y = 2;
	p[0].coord[3].x = 0;
	p[0].coord[3].y = 3;
	p[0].placed = FALSE;
	p[0].next = &p[1];

	p[1].id = 1;
	p[1].type = 1;
	p[1].coord[0].x = 0;
	p[1].coord[0].y = 0;
	p[1].coord[1].x = 1;
	p[1].coord[1].y = 0;
	p[1].coord[2].x = 2;
	p[1].coord[2].y = 0;
	p[1].coord[3].x = 3;
	p[1].coord[3].y = 0;
	p[1].placed = FALSE;
	p[1].next = &p[2];

	p[2].id = 2;
	p[2].type = 2;
	p[2].coord[0].x = 0;
	p[2].coord[0].y = 0;
	p[2].coord[1].x = 1;
	p[2].coord[1].y = 0;
	p[2].coord[2].x = 2;
	p[2].coord[2].y = 0;
	p[2].coord[3].x = 2;
	p[2].coord[3].y = 1;
	p[2].placed = FALSE;
	p[2].next = &p[3];

	p[3].id = 3;
	p[3].type = 3;
	p[3].coord[0].x = 1;
	p[3].coord[0].y = 0;
	p[3].coord[1].x = 2;
	p[3].coord[1].y = 0;
	p[3].coord[2].x = 0;
	p[3].coord[2].y = 1;
	p[3].coord[3].x = 1;
	p[3].coord[3].y = 1;
	p[3].placed = FALSE;
	p[3].next = &p[4];

	p[4].id = 4;
	p[4].type = 4;
	p[4].coord[0].x = 0;
	p[4].coord[0].y = 0;
	p[4].coord[1].x = 0;
	p[4].coord[1].y = 1;
	p[4].coord[2].x = 1;
	p[4].coord[2].y = 0;
	p[4].coord[3].x = 1;
	p[4].coord[3].y = 1;
	p[4].placed = FALSE;
	p[4].next = &p[5];

	p[5].id = 5;
	p[5].type = 5;
	p[5].coord[0].x = 0;
	p[5].coord[0].y = 0;
	p[5].coord[1].x = 1;
	p[5].coord[1].y = 0;
	p[5].coord[2].x = 1;
	p[5].coord[2].y = 1;
	p[5].coord[3].x = 2;
	p[5].coord[3].y = 1;
	p[5].placed = FALSE;
	p[5].next = &p[6];

	p[6].id = 6;
	p[6].type = 6;
	p[6].coord[0].x = 0;
	p[6].coord[0].y = 0;
	p[6].coord[1].x = 1;
	p[6].coord[1].y = 0;
	p[6].coord[2].x = 1;
	p[6].coord[2].y = 1;
	p[6].coord[3].x = 1;
	p[6].coord[3].y = 2;
	p[6].placed = FALSE;
	p[6].next = &p[7];

	p[7].id = 7;
	p[7].type = 7;
	p[7].coord[0].x = 0;
	p[7].coord[0].y = 0;
	p[7].coord[1].x = 1;
	p[7].coord[1].y = 0;
	p[7].coord[2].x = 1;
	p[7].coord[2].y = 1;
	p[7].coord[3].x = 2;
	p[7].coord[3].y = 0;
	p[7].placed = FALSE;
	p[7].next = NULL;

	fi.list = &p[0];
	map_create(&fi.map, fi.list_size * PIECE_MAX_LENGTH);
	fi.map.size = 1;
	while (fi.map.size * fi.map.size < fi.list_size * PIECE_MAX_LENGTH)
		fi.map.size++;
	while (ft_rec(&fi, 0) != EXIT_FINISH)
		fi.map.size++;
	map_print(&fi.map, fi.to_color);
	return (0);
}
