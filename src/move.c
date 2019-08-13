/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:13:17 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/12 18:44:46 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	move(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (i < (map->plateau_y - map->piece_y) && i < map->piece_y)
	{
		j = 0;
		while (j < (map->plateau_x - map->piece_x) && i < map->piece_x)
		{
			if (map->figure_map[i][j] == '*' && map->plate_int[i][j] == 0)
				ft_printf("%s", "overlap");
			j++;
		}
		i++;
	}
}
// void	check_figure()
// {

// }



