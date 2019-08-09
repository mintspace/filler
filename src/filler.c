/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:42:07 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/08 20:01:14 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_map *map)
{
	char	*str;

	get_next_line(map->fd, &str);
	if (ft_strstr(str, "dbubnov"))
		map->player = 'X';
	else
		map->player = 'O';
	ft_strdel(&str);
}

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

	map->plateau_map = (char **)malloc(sizeof(char *) * (map->plateau_y + 1));
	get_next_line(map->fd, &str);
	ft_strdel(&str);
	i = 0;
	while (i < map->plateau_y)
	{
		map->plateau_map[i] = ft_strnew(map->plateau_x);
		get_next_line(map->fd, &str);
		ft_strcpy(map->plateau_map[i++], ft_strchr(str, ' ') + 1);
		ft_strdel(&str);
	}
	map->plateau_map[i] = NULL;
}

void	get_piece(t_map *map)
{
	char *str;

	while (1)
	{
		get_next_line(map->fd, &str);
		if (ft_strstr(str, "Piece"))
			break ;
		ft_strdel(&str);
	}
	map->piece_x = ft_atoi(ft_strrchr(str, ' '));
	map->piece_y = ft_atoi(ft_strchr(str, ' '));
	ft_strdel(&str);
}

void	get_figure(t_map *map)
{
	char	*str;
	int		i;

	map->figure_map = (char **)malloc(sizeof(char *) * (map->piece_y + 1));
	i = 0;
	while (i < map->piece_y)
	{
		map->figure_map[i] = ft_strnew(map->piece_x);
		get_next_line(map->fd, &str);
		ft_strcpy(map->figure_map[i++], str);
		ft_strdel(&str);
	}
	map->figure_map[i] = NULL;
}

t_map	*map_read(int fd)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->fd = fd;
	get_player(map);
	get_plateau(map);
	get_map(map);
	get_piece(map);
	get_figure(map);

	return (map);
}

int		main(void)
{
	int		fd;
	int		i;
	t_map	*map;

	i = 0;
	fd = open("src/filler.txt", O_RDONLY);
	map = map_read(fd);

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

	close(fd);
	return (0);
}
