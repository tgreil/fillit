#include "fillit.h"
void		ft_print(t_piece *piece)
{
	int i = 0;
	printf("numero : %d\n");
	while (i < 4)
	{
		printf("coord[%d].x = %d", i, (piece->coord[i]).x);
		printf("coord[%d].y = %d", i, (piece->coord[i]).y);
		i++;
	}
}
int		tetriminos_error_handler(t_piece *piece)
{
	int i;
	int j;
	int is_ok;

	i = 0;
	while (i < 4)
	{
		j = 0;
		is_ok = 0;
		while (j < 4)
		{
			if (j != i && is_ok == 0)
			{
				if ((((piece->coord[i]).x) - ((piece->coord[j]).x)) == 1 || (((piece->coord[i]).x) - ((piece->coord[j]).x)) == -1 ||
				(((piece->coord[i]).y) - ((piece->coord[j].y))) == 1 || (((piece->coord[i]).x) - ((piece->coord[j]).x)) == -1)
					is_ok++;
			}
			j++;
		}
		if (is_ok == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
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
