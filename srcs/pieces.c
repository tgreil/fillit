#include "fillit.h"

void		piece_end(t_piece *list)
{
	t_piece	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_piece		*piece_create(int id)
{
	t_piece	*new;

	if (!(new = malloc(sizeof(t_piece))))
		return (NULL);
	new->placed = FALSE;
	new->id = id;
	new->type = id;
	new->next = NULL;
	return (new);
}

t_piece		*pieces_get_byindex(t_piece *list, int index)
{
	t_piece		*tmp;
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

int		piece_count(t_piece *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
