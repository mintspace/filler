/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:13:17 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/13 00:54:55 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	move(t_map *map, int start_x, int start_y)
{
	int	i;
	int j;

	i = 0;
	while (start_y < (map->plateau_y - map->piece_y) && i < map->piece_y)
	{
		j = 0;
		while (start_x < (map->plateau_x - map->piece_x) && j < map->piece_x)
		{
			if (map->figure_map[i][j] == '*' && map->plate_int[start_y][start_x] == 0)
			{
				ft_printf("enemy: y = %d, x = %d\n", start_y, start_x);
				break ;
			}
			j++;
			start_x++;
		}
		i++;
		start_y++;
	}
}
void	check_figure(t_map *map)
{
	int	start_x;
	int start_y;

	start_y = 0;
	while (start_y < (map->plateau_x - map->piece_x))
	{
		start_x = 0;
		while (start_x < (map->plateau_y - map->piece_y))
		{
			move(map, start_x, start_y);
			start_x++;
		}
		start_y++;
	}
}



