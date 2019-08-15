/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:13:17 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/14 15:05:00 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	move(t_map *map, int start_x, int start_y)
{
	int	i;
	int j;
	int x;
	int y;

	i = 0;
	y = start_y;

	while (y < ((map->plateau_y + 1) - map->piece_y) && i < map->piece_y)
	{
		j = 0;
		x = start_x;
		while (x < ((map->plateau_y + 1)- map->piece_x) && j < map->piece_x)
		{
			if (map->figure_map[i][j] == '*' && map->plate_int[y][x] == ENEMY)
				break ;
			if (map->figure_map[i][j] == '*' && map->plate_int[y][x] == PLAYER)
			{
				lowest_summ(map, start_x, start_y);
				break ;
			}
			j++;
			x++;
		}
		i++;
		y++;
	}
}
void	check_figure(t_map *map)
{
	int	start_x;
	int start_y;

	start_y = 0;
	while (start_y < ((map->plateau_x + 1) - map->piece_x))
	{
		start_x = 0;
		while (start_x < ((map->plateau_y + 1) - map->piece_y))
		{
			move(map, start_x, start_y);
			start_x++;
		}
		start_y++;
	}
}

void	lowest_summ(t_map *map, int start_x, int start_y)
{
	int	sum;
	int x;
	int y;

	sum = 0;
	x = start_x;
	y = start_y;
	while (start_y < (y + map->piece_y))
	{
		while (start_x < (x + map->piece_x))
		{
			sum += map->plate_int[start_y][start_x];
			start_x++;
		}
		start_y++;
	}
	if (sum < map->l_sum)
	{
		map->l_sum = sum;
		map->return_x = x;
		map->return_y = y;
	}
}
