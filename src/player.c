/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:13:10 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/14 14:56:56 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_map *map)
{
	char	*str;

	while (1)
	{
		get_next_line(map->fd, &str);
		if (ft_strstr(str, "$$$ exec p"))
			break ;
	}
	if (ft_strstr(str, "1"))
	{
		map->player = 'O';
		map->enemy = 'X';
	}
	else
	{
		map->player = 'X';
		map->enemy = 'O';
	}
	ft_strdel(&str);
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
