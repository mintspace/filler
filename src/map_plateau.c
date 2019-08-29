/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:11:00 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/29 08:58:35 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_plateau(t_map *map)
{
	char	*str;

	while (1)
	{
		get_next_line(map->fd, &str);
		if (ft_strstr(str, "Plateau"))
			break ;
		ft_strdel(&str);
	}
	map->plateau_x = ft_atoi(ft_strrchr(str, ' '));
	map->plateau_y = ft_atoi(ft_strchr(str, ' '));
	ft_strdel(&str);
}

void	get_map(t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	map->plateau_map = (char **)malloc(sizeof(char *) * (map->plateau_y + 1));
	while (i < map->plateau_y)
	{
		get_next_line(map->fd, &str);
		if (ft_strstr(str, "01234567890"))
			continue ;
		map->plateau_map[i] = ft_strnew(map->plateau_x);
		ft_strcpy(map->plateau_map[i++], ft_strchr(str, ' ') + 1);
		ft_strdel(&str);
	}
	map->plateau_map[i] = NULL;
}

void	heat_map_check(t_map *map, int i, int j)
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
