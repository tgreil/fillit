#include "fillit.h"

int		fillit(t_map *map, t_piece *piece, int p_placed, int p_nbr)
{
	int	x;
	int y;

	y = 0;
	if (p_placed == p_nbr)
		return (EXIT_FINISH);
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map_add_piece(map, piece, x, y) == TRUE)
			{
				piece->placed = TRUE;
				if (fillit(map, piece->next, p_placed + 1, p_nbr) == EXIT_F)
					return (EXIT_FINISH);
				map_remove_piece(map, piece);
				piece->placed = FALSE;
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int		ft_fillit_exit(t_fillit *fi)
{
	map_end(&fi->map);
	piece_end(fi->list);
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
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
	map_create(&fi.map, fi.list_size * PIECE_MAX_LENGTH);
	map_calc_minsize(&fi.map, fi.list_size);
	while (fillit(&fi.map, fi.list, 0, fi.list_size) != EXIT_FINISH)
		fi.map.size++;
	map_print(&fi.map, fi.to_color);
	close(fd);
	return (ft_fillit_exit(&fi));
}
