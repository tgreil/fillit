#include "fillit.h"

int	ft_fillit_place(t_fillit *fi, t_piece *piece, int pieces_placed)
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
				if (ft_fillit(fi, pieces_placed + 1) == EXIT_FINISH)
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

int	ft_fillit(t_fillit *fi, int pieces_placed)
{
	t_piece	*piece;
	int		i;

	i = 0;
	map_print_nl(&fi->map, TRUE);
	if (pieces_placed == fi->list_size)
		return (EXIT_FINISH);
	while (i < fi->list_size)
	{
		piece = pieces_get_byindex(fi->list, i);
		if (piece->placed == FALSE)
		{
			if (ft_fillit_place(fi, piece, pieces_placed) == EXIT_FINISH)
				return (EXIT_FINISH);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_fillit_exit(t_fillit *fi)
{
	map_end(&fi->map);
	piece_end(fi->list);
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	t_fillit	fi;
	int			fd;

	if (ac != 2)
		return (EXIT_ERROR);
	fi.to_color = TRUE;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (EXIT_ERROR); // ERROR MESG OPEN
	if (!(fi.list = pieces_get(fd)))
		return (EXIT_ERROR + ft_putstr(ERROR_MSG));
	fi.list_size = piece_count(fi.list);
	map_create(&fi.map, fi.list_size * PIECE_MAX_LENGTH / 2);
	map_calc_minsize(&fi.map, fi.list_size);
	while (ft_fillit(&fi, 0) != EXIT_FINISH)
		fi.map.size++;
	map_print(&fi.map, fi.to_color);
	close(fd);
	return (ft_fillit_exit(&fi));
}
