/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:35:05 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/03 15:35:06 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_calc_minsize(t_map *map, int list_size)
{
	int	min;

	min = 1;
	while (min * min < list_size * PIECE_MAX_LENGTH)
		min++;
	map->size = min;
	return (min);
}
