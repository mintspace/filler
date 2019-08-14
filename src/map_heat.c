/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:58:47 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/14 05:52:35 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	int_map_int(t_map *map)
{
	int i;

	i = 0;
	map->plate_int = (int **)malloc(sizeof(int *) * (map->plateau_y));
	while (i < map->plateau_y)
	{
		map->plate_int[i] = (int *)malloc(sizeof(int) * (map->plateau_x));
		i++;
	}
}

void	fill_map_int(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->plateau_y)
	{
		j = 0;
		while (j < map->plateau_x)
		{
			if (map->plateau_map[i][j] == '.')
				map->plate_int[i][j] = EMPTY_FIELD;
			if (map->plateau_map[i][j] == map->player)
				map->plate_int[i][j] = PLAYER;
			if (map->plateau_map[i][j] == map->enemy)
				map->plate_int[i][j] = ENEMY;
			j++;
		}
		i++;
	}
}

void	heat_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->heat_number = 1;
	map->round = 0;
	while (i < map->plateau_y)
	{
		j = 0;
		while (j < map->plateau_x)
		{
			if (map->plate_int[i][j] == PLAYER)
				map->plate_int[i][j] = PLAYER;

			if (map->plate_int[i][j] == map->round
				&& (i - 1) >= 0 && (j - 1) >= 0
				&& (j + 1) < map->plateau_x && (i + 1) < map->plateau_y)
			{
				if (map->plate_int[i][j + 1] == EMPTY_FIELD)
					map->plate_int[i][j + 1] = map->heat_number;
				if (map->plate_int[i][j - 1] == EMPTY_FIELD)
					map->plate_int[i][j - 1] = map->heat_number;
				if (map->plate_int[i + 1][j] == EMPTY_FIELD)
					map->plate_int[i + 1][j] = map->heat_number;
				if (map->plate_int[i - 1][j] == EMPTY_FIELD)
					map->plate_int[i - 1][j] = map->heat_number;
				if (map->plate_int[i + 1][j + 1] == EMPTY_FIELD)
					map->plate_int[i + 1][j + 1] = map->heat_number;
				if (map->plate_int[i - 1][j - 1] == EMPTY_FIELD)
					map->plate_int[i - 1][j - 1] = map->heat_number;
				if (map->plate_int[i + 1][j - 1] == EMPTY_FIELD)
					map->plate_int[i + 1][j - 1] = map->heat_number;
				if (map->plate_int[i - 1][j + 1] == EMPTY_FIELD)
					map->plate_int[i - 1][j + 1] = map->heat_number;
			}
			j++;
		}
		i++;
	}
}

void	fill_heat_map(t_map *map)
{
	int i;
	int j;

	i = 0;

	while (i < map->plateau_y)
	{
		j = 0;
		while (j < map->plateau_x)
		{
			if (map->plate_int[i][j] == map->heat_number
				&& (i - 1) >= 0 && (j - 1) >= 0
				&& (j + 1) < map->plateau_x && (i + 1) < map->plateau_y)
			{
				if (map->plate_int[i][j + 1] == EMPTY_FIELD)
					map->plate_int[i][j + 1] = map->heat_number + 1;
				if (map->plate_int[i][j - 1] == EMPTY_FIELD)
					map->plate_int[i][j - 1] = map->heat_number + 1;
				if (map->plate_int[i + 1][j] == EMPTY_FIELD)
					map->plate_int[i + 1][j] = map->heat_number + 1;
				if (map->plate_int[i - 1][j] == EMPTY_FIELD)
					map->plate_int[i - 1][j] = map->heat_number + 1;
				if (map->plate_int[i + 1][j + 1] == EMPTY_FIELD)
					map->plate_int[i + 1][j + 1] = map->heat_number + 1;
				if (map->plate_int[i - 1][j - 1] == EMPTY_FIELD)
					map->plate_int[i - 1][j - 1] = map->heat_number + 1;
				if (map->plate_int[i + 1][j - 1] == EMPTY_FIELD)
					map->plate_int[i + 1][j - 1] = map->heat_number + 1;
				if (map->plate_int[i - 1][j + 1] == EMPTY_FIELD)
					map->plate_int[i - 1][j + 1] = map->heat_number + 1;
			}
			j++;
		}
		i++;
	}
}
