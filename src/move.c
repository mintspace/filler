/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:13:17 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/29 09:40:41 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	small_move(t_map *map, int i, int j)
{
	int x;
	int y;

	y = map->start_y;
	while (i < map->piece_y)
	{
		j = 0;
		x = map->start_x;
		while (j < map->piece_x)
		{
			if (map->figure_map[i][j] == '*' && map->plate_int[y][x] == ENEMY)
			{
				map->coincidence_enemy++;
				break ;
			}
			if (map->figure_map[i][j] == '*' && map->plate_int[y][x] == PLAYER)
				map->coincidence++;
			j++;
			x++;
		}
		i++;
		y++;
	}
}

void	check_figure(t_map *map)
{
	map->return_x = 0;
	map->return_y = 0;
	map->start_y = 0;
	while (map->start_y <= (map->plateau_y - map->piece_y))
	{
		map->start_x = 0;
		while (map->start_x <= (map->plateau_x - map->piece_x))
		{
			map->coincidence = 0;
			map->coincidence_enemy = 0;
			small_move(map, 0, 0);
			if (map->coincidence == 1 && map->coincidence_enemy == 0)
				lowest_summ(map, map->start_x, map->start_y);
			map->start_x++;
		}
		map->start_y++;
	}
}

void	lowest_summ_check(t_map *map, int sum, int x_return, int y_return)
{
	if (sum < map->l_sum)
	{
		map->l_sum = sum;
		map->return_x = x_return;
		map->return_y = y_return;
	}
}

void	lowest_summ(t_map *map, int start_x, int start_y)
{
	int x;
	int y;
	int	sum;
	int x_return;
	int y_return;

	y = 0;
	sum = 0;
	x_return = start_x;
	y_return = start_y;
	while (start_y < (y_return + map->piece_y) && start_y < map->plateau_y)
	{
		x = 0;
		start_x = x_return;
		while (start_x < (x_return + map->piece_x) & start_x < map->plateau_x)
		{
			if (map->figure_map[y][x] == '*')
				sum += map->plate_int[start_y][start_x];
			start_x++;
			x++;
		}
		start_y++;
		y++;
	}
	lowest_summ_check(map, sum, x_return, y_return);
}
