#include "fillit.h"

void		ft_print(t_piece *piece)
{
	int i = 0;
	printf("numero : %d\n", piece->id);
	while (i < 4)
	{
		printf("coord[%d].x = %d et", i, (piece->coord[i]).x);
		printf("coord[%d].y = %d\n", i, (piece->coord[i]).y);
		i++;
	}
}
int		tetriminos_error_handler(t_piece *piece)
{
	int i;
	int j;
	int bound = 0;
	int two_bound = 0;
	int one_bound = 0;
	int three_bound = 0;
	i = 0;
	ft_print(piece);
	while (i < 4)
	{
		j = 0;
		bound = 0;
		while (j < 4)
		{
			if (j != i)
			{
			if (piece->coord[i].y == piece->coord[j].y && piece->coord[i].x == (piece->coord[j].x + 1))
				bound++;
			if (piece->coord[i].y == piece->coord[j].y && piece->coord[i].x == (piece->coord[j].x - 1))
				bound++;
			if (piece->coord[i].x == piece->coord[j].x && piece->coord[i].y == (piece->coord[j].y + 1))
				bound++;
			if (piece->coord[i].x == piece->coord[j].x && piece->coord[i].y == (piece->coord[j].y - 1))
				bound++;
			}
			j++;

		}
		if (bound == 2)
			two_bound++;
		else if (bound == 1)
			one_bound++;
		else if (bound == 3)
			three_bound++;
		i++;
	}
	printf("three == %d et two = %d et one = %d\n", three_bound, two_bound, one_bound);
	if ((one_bound + two_bound + three_bound == 4) && ((two_bound >= 2) || (three_bound == 1)))
		return (TRUE);
	printf("%d\n", bound);
	//if (bound == 6)
	//	return (TRUE);
	return (FALSE);
}
int		pre_check_errors(char *buf, int ret)
{
	int i;
	int blocks_count;

	if (ret < 20)
		return (FALSE);
	blocks_count = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			blocks_count++;
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (FALSE);
		if ((i % 5) == 4 && buf[i] != '\n') // fin de ligne
			return (FALSE);
		i++;
	}
	if (ret == 21 && buf[20] != '\n')
		return (FALSE);
	if (blocks_count != 4)
		return (FALSE);
	return (TRUE);
}
