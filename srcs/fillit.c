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

int main(int ac, char **av)
{
	t_fillit	fi;
	t_piece		*list;
	int			fd;

	if (ac != 2)
		return (EXIT_ERROR);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (EXIT_ERROR); // ERROR MESG OPEN
	list = pieces_get(fd);
	fi.list = list;
	fi.list_size++;
	while (list)
	{
		list = list->next;
		fi.list_size++;
	}
	map_create(&fi.map, fi.list_size * PIECE_MAX_LENGTH);
	while (ft_rec(&fi, 0) != EXIT_FINISH)
		fi.map.size++;
	map_print(&fi.map, fi.to_color);
	close(fd);
	return (0);
}
