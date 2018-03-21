#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUF_SIZE			21
# define PIECE_MAX_LENGTH	4
# define EXIT_SUCCESS		0
# define EXIT_ERROR			-1
# define EXIT_FINISH		1
# define EXIT_F				EXIT_FINISH
# define TRUE				1
# define FALSE				0
# define COLOR_NB			7
# define ERROR_MSG			"error\n"

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_piece
{
	char				placed;
	char				type;
	int					id;
	t_coord				coord[PIECE_MAX_LENGTH];
	struct s_piece		*next;
}						t_piece;

typedef struct			s_map
{
	int					init_size;
	int					size;
	t_piece				***grid;
}						t_map;

typedef struct			s_fillit
{
	t_map				map;
	t_piece				*list;
	int					list_size;
	char				to_color;
}						t_fillit;

/*
**			utils.c
*/
void					ft_tabtab_cpy(t_piece ***des, t_piece ***src, int size);
int						ft_putstr(char *str);
int						ft_putchar(int c);

/*
**			map.c && map_calc.c && map_print.c
*/
void					map_end(t_map *map);
int						map_add_piece(t_map *map, t_piece *piece, int x, int y);
int						map_remove_piece(t_map *map, t_piece *piece);
int						map_create(t_map *map, int size);

int						map_calc_minsize(t_map *map, int list_size);

void					map_print(t_map *map, char to_color);
void					map_print_nl(t_map *map, char to_color);

/*
**			pieces.c
*/
void					piece_end(t_piece *list);
t_piece					*piece_create(int id);
t_piece					*pieces_get_byindex(t_piece *list, int index);
int						piece_count(t_piece *list);

/*
**			parser.c
*/
t_piece					*pieces_get(int fd);

/*
**			fillit.c
*/
int						fillit(t_map *map, t_piece *p, int p_p, int p_n);

/*
**			errors_handlers.c
*/

int					pre_check_errors(char *buf, int ret);
#endif
