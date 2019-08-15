/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:11:00 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/14 17:08:49 by metalium         ###   ########.fr       */
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
	map->plateau_map = (char **)malloc(sizeof(char *) * (map->plateau_y + 1));
	ft_strdel(&str);
}

void	get_map(t_map *map)
{
	char	*str;
	int		i;

	// get_next_line(map->fd, &str);
	// ft_strdel(&str);
	// while (1)
	// {
	// 	get_next_line(map->fd, &str);
	// 	if (ft_strstr(str, "01234567890"))
	// 	{
	// 		// get_next_line(map->fd, &str);
	// 		break ;
	// 	}
	// 	// ft_strdel(&str);
	// }
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
