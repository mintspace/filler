/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:42:07 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/29 08:57:58 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*first_read(int fd)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->fd = fd;
	get_player(map);
	get_plateau(map);
	return (map);
}

void	game_start(t_map *map)
{
	int		i;

	i = 0;
	get_map(map);
	get_piece(map);
	get_figure(map);
	int_map_int(map);
	fill_map_int(map);
	heat_map(map);
	while (i < map->plateau_x)
	{
		fill_heat_map(map);
		map->heat_number++;
		i++;
	}
	map->l_sum = 10000000;
	check_figure(map);
	ft_printf("%d %d\n", map->return_y, map->return_x);
}

int		main(void)
{
	int		fd;
	t_map	*map;
	char	*str;

	fd = 0;
	map = first_read(fd);
	while (get_next_line(map->fd, &str) > 0)
		game_start(map);
	close(fd);
	return (0);
}
