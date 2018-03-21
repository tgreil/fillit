#include "fillit.h"

int		get_bounds(int x[4], int y[4], int i)
{
	int bound;
	int j;

	j = 0;
	bound = 0;
	while (j < 4)
	{
		if (j != i)
		{
			if (y[i] == y[j] && x[i] == (x[j] + 1))
				bound++;
			if (y[i] == y[j] && x[i] == (x[j] - 1))
				bound++;
			if (x[i] == x[j] && y[i] == (y[j] + 1))
				bound++;
			if (x[i] == x[j] && y[i] == (y[j] - 1))
				bound++;
		}
		j++;
	}
	return (bound);
}
int		tetriminos_error_handler(int x[4], int y[4])
{
	int i;
	int two_bound;
	int one_bound;
	int three_bound;

	one_bound = 0;
	two_bound = 0;
	three_bound = 0;
	i = 0;
	while (i < 4)
	{
		if (get_bounds(x, y, i) == 2)
			two_bound++;
		else if (get_bounds(x, y, i) == 1)
			one_bound++;
		else if (get_bounds(x, y, i) == 3)
			three_bound++;
		i++;
	}
//	printf("three == %d et two = %d et one = %d\n", three_bound, two_bound, one_bound);
	if ((one_bound + two_bound + three_bound == 4) && ((two_bound >= 2) || (three_bound == 1)))
		return (TRUE);
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
