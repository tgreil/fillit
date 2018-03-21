#include "fillit.h"

int		fillit_prepare(t_piece *piece)
{
	if (piece->binome)
	{
		piece->pos.x = piece->binome->pos.x;
		piece->pos.y = piece->binome->pos.y;
		return (FALSE);
	}
	piece->pos.x = 0;
	piece->pos.y = 0;
	return (TRUE);
}

int		fillit(t_fillit *fi, t_piece *piece, int p_placed, int p_nbr)
{
	int			flag;

	if (p_placed == p_nbr)
		return (EXIT_FINISH);
	flag = fillit_prepare(piece);
	while (piece->pos.y < fi->map.size)
	{
		if (flag == TRUE)
			piece->pos.x = 0;
		while (piece->pos.x < fi->map.size)
		{
			if (map_add_piece(&fi->map, piece) == TRUE)
			{
				if (fillit(fi, piece->next, p_placed + 1, p_nbr) == EXIT_F)
					return (EXIT_FINISH);
				map_remove_piece(&fi->map, piece);
			}
			else if (map_add_piece(&fi->map, piece) == MAP_LIMIT)
				return (EXIT_SUCCESS);
			piece->pos.x++;
		}
		flag = TRUE;
		piece->pos.y++;
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
	piece_link_same(fi.list, fi.list);
	map_calc_minsize(&fi.map, fi.list_size);
	while (fillit(&fi, fi.list, 0, fi.list_size) != EXIT_FINISH)
		fi.map.size++;
	map_print(&fi.map, fi.to_color);
	close(fd);
	return (ft_fillit_exit(&fi));
}
