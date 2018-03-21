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
void	get_shape(char *buf, t_piece *new_piece)
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
	get_x_y(x, y, new_piece);
}
void	fill_struct(t_piece **begin_list, char *buf, int piece_rank)
{
	t_piece *new_piece;
	t_piece *tmp;

	tmp = *begin_list;
	if ((new_piece = malloc(sizeof(t_piece))) == NULL)
		return ;
	new_piece->placed = FALSE;
	new_piece->type = piece_rank; // piece_type_get
	new_piece->id = piece_rank;
	new_piece->next = NULL;
	get_shape(buf, new_piece);
	if (!(*begin_list))
		*begin_list = new_piece;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_piece;
	}
}

t_piece		*pieces_get(int fd)
{
	char		buf[BUF_SIZE];
	t_piece		*pieces_list;
	int			piece_rank;
	int		ret;
	int		final_ret;
	piece_rank = 0;
	pieces_list = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (pre_check_errors(buf, ret) == FALSE)
			return (NULL);
		fill_struct(&pieces_list, buf, piece_rank);
		final_ret = ret;
		piece_rank++;
	}
	if (final_ret != 20) // error handle, pas de new line a la fin
		return (NULL);
	return (pieces_list);
}
