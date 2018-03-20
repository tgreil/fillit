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
		(new_piece->coord[i]).x = x_old[i] - x_min;
		(new_piece->coord[i]).y = y_old[i] - y_min;
		i++;
	}
}
void	get_shape(char buf[BUF_SIZE], t_piece *new_piece)
{
	int x[4];
	int y[4];
	int i;
	int k;
	int j;

	j = 0;
	i = 0;
	k = 0;
	while (i < 20)
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
void	fill_struct(t_piece **begin_list, char buf[BUF_SIZE], int piece_rank)
{
	t_piece *new_piece;
	t_piece *tmp;

	tmp = *begin_list;
	if ((new_piece = malloc(sizeof(t_piece))) == NULL)
		return ;
	new_piece->placed = 0;
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
//int	basic_validity_check(char buf[BUF_SIZE + 1])
//{
//	int i;
//	while (buf[i])
//	{
//
//	}
//}
//void	print_struct(t_piece *list)
//{
//	int i;
//
//	i = 0;
//	printf ("Piece number %d\n", list->id);
//	while (i < 4)
//	{
//		printf("x = %d et y = %d\n\n", (list->coord[i]).x, (list->coord[i]).y);
//		i++;
//	}
//}
t_piece		*pieces_get(int fd)
{
	char		buf[BUF_SIZE];
	t_piece		*pieces_list;
	int			piece_rank;

	piece_rank = 0;
	pieces_list = NULL;
	while (read(fd, buf, BUF_SIZE))
	{
//		if ((basic_validity_check(buf) == FALSE)
//			//error
		fill_struct(&pieces_list, buf, piece_rank);
		piece_rank++;
	}
//	while (i < 4)
//	{
//		print_struct(pieces_list);
//		i++;
//		pieces_list = pieces_list->next;
//	}
	return (pieces_list);
}
