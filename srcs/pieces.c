#include "fillit.h"

t_pieces		*pieces_get_byindex(t_pieces *list, int index)
{
	t_pieces	*tmp;
	int			i_index;

	i_index = 0;
	tmp = list;
	while (tmp && i_index < index)
	{
		tmp = tmp->next;
		i_index++;
	}
	if (!tmp)
		return (list);
	return (tmp);
}
