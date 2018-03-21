#include "fillit.h"

int		pre_check_errors(char *buf, int ret)
{
	int i;
	int blocks_count;
	int line_length;

	if (ret < 20)
		return (FALSE);
	blocks_count = 0;
	line_length = 0;
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
