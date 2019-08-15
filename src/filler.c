/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:42:07 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/14 23:47:45 by metalium         ###   ########.fr       */
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
	map->l_sum = 1000;
	check_figure(map);
	ft_printf("%d %d\n", map->return_y, map->return_x);
}

int		main(void)
{
	int		fd;
	int i;
	int j;
	t_map	*map;
	char	*str;
	// fd = 0;
	fd = open("src/filler.txt", O_RDONLY);

	map = first_read(fd);
	while (get_next_line(map->fd, &str) > 0)
	{
		game_start(map);

		i = 0;
		ft_printf("player: y = %d, x = %d, sum: %d\n", map->return_y, map->return_x, map->l_sum);
		ft_printf("player: %c\n", map->player);
		ft_printf("plateau_x: %d\n", map->plateau_x);
		ft_printf("plateau_y: %d\n", map->plateau_y);
		while (map->plateau_map[i])
			ft_printf("%s\n", map->plateau_map[i++]);
		ft_printf("piece_x: %d\n", map->piece_x);
		ft_printf("piece_y: %d\n", map->piece_y);
		i = 0;
		while (map->figure_map[i])
			ft_printf("%s\n", map->figure_map[i++]);
		i = 0;

		while (i < map->plateau_y)
		{
			j = 0;
			while (j < map->plateau_x)
			{
				ft_printf("%2d ", map->plate_int[i][j]);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}


//-----------------------------------------------------------------------


//-----------------------------------------------------------------------

	close(fd);
	return (0);
}


