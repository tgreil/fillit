#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define PIECE_MAX_LENGTH	4
# define EXIT_SUCCESS		0
# define EXIT_ERROR			-1
# define EXIT_FINISH		1
# define TRUE				1
# define FALSE				0

typedef struct			s_coord;
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_piece
{
	char				placed;
	char				type;
	char				letter;
	t_coord				coord[PIECE_MAX_LENGTH];
	struct s_pieces		*next;
}						t_piece;

typedef struct			s_map
{
	int					size;
	t_piece				***grid;
}						t_map;

typedef struct			s_fillit
{
	s_map				map;
	t_map				result;
	t_piece				*list;
	int					list_size;
}						t_fillit;

/*
**			map.c
*/
int						map_create(t_map *map, int size);

/*
**			pieces.c
*/
t_pieces				*pieces_get_byindex(t_pieces *list, int index);

#endif
