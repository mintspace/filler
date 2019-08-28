/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:13:17 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/28 09:06:26 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void small_move(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= map->piece_y)
	{
		while (j <= map->piece_x)
		{

			j++;
		}
		i++;
	}
}

void move(t_map *map, int start_x, int start_y)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while ()
}
// void	move(t_map *map, int start_x, int start_y)
// {
// 	int	i;
// 	int j;
// 	int x;
// 	int y;

// 	map->coincidence = 0;
// 	map->coincidence_enemy = 0;
// 	i = 0;
// 	y = start_y;
// 	x = start_x;
// 	while (y < (map->plateau_y - start_y) && x < (map->plateau_x - start_x))
// 	{
// 		j = 0;
// 		x = start_x;
// 		while (i < map->piece_y && j < map->piece_x)
// 		{
// 			if (map->figure_map[i][j] == '*' && map->plate_int[y][x] == ENEMY)
// 			{
// 				map->coincidence_enemy++;
// 				break ;
// 			}
// 			if (map->figure_map[i][j] == '*' && map->plate_int[y][x] == PLAYER)
// 				map->coincidence++;
// 			j++;
// 			x++;
// 		}
// 		i++;
// 		y++;
// 	}
// 	if (map->coincidence == 1 && map->coincidence_enemy == 0)
// 		lowest_summ(map, start_x, start_y);
// }



void	check_figure(t_map *map)
{
	int	start_x;
	int start_y;

	map->return_x = 0;
	map->return_y = 0;
	start_y = 0;
	while (start_y <= (map->plateau_x - map->piece_x))
	{
		start_x = 0;
		while (start_x <= (map->plateau_y - map->piece_y))
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
	int x_return;
	int y_return;

	sum = 0;
	x_return = start_x;
	y_return = start_y;
	y = 0;
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
	if (sum < map->l_sum)
	{
		map->l_sum = sum;
		map->return_x = x_return;
		map->return_y = y_return;
	}
}
