#include "fillit.h"

void	get_x_y(int x_old[4], int y_old[4], t_piece *new_piece)
{
	int x_min;
	int y_min;
	int i;

	x_min = 10;
	y_min = 10;
	i = 0;
	while (i < 4)
	{
		x_min = x_old[i] < x_min ? x_old[i] : x_min;
		y_min = y_old[i] < y_min ? y_old[i] : y_min;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		new_piece->coord[i].x = x_old[i] - x_min;
		new_piece->coord[i].y = y_old[i] - y_min;
		i++;
	}
}
int	get_shape(char *buf, t_piece *new_piece)
{
	int x[4];
	int y[4];
	int i;
	int k;
	int j;

	j = 0;
	i = 0;
	k = 0;
	while (i < BUF_SIZE)
	{
		if (buf[i] == '#')
		{
			x[k] = j % 4;
			y[k] = j / 4;
			k++;
		}
		if (buf[i] != '\n')
			j++;
		i++;
	}
	if (tetriminos_error_handler(x, y) == FALSE)
		return (FALSE);
	get_x_y(x, y, new_piece);
	return (TRUE);
}
int		fill_struct(t_piece **begin_list, char *buf, int piece_rank)
{
	t_piece *new;
	t_piece *tmp;

	tmp = *begin_list;
	if (!(new = piece_create(piece_rank)))
		return (EXIT_ERROR);
	if (get_shape(buf, new) == FALSE)
		return (EXIT_ERROR);
	if (!(*begin_list))
		*begin_list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (EXIT_SUCCESS);
}

t_piece		*pieces_get(int fd)
{
	char		buf[BUF_SIZE];
	t_piece		*pieces_list;
	int			piece_rank;
	int			ret;
	int			final_ret;

	final_ret = 0;
	piece_rank = 0;
	pieces_list = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (pre_check_errors(buf, ret) == FALSE)
			return (NULL);
		if (fill_struct(&pieces_list, buf, piece_rank) == EXIT_ERROR)
			return (NULL);
//		if (tetriminos_error_handler(pieces_list) == FALSE)
//			return (NULL);
		final_ret = ret;
		piece_rank++;
	}
	if (final_ret != 20) // error handle, pas de new line a la fin
		return (NULL);
	return (pieces_list);
}
