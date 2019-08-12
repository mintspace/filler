/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:46:27 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/12 15:59:14 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

# define PLAYER -4
# define ENEMY 0
# define EMPTY_FIELD -1

typedef struct	s_map
{
	int			fd;
	char		player;
	char		enemy;
	int			plateau_x;
	int			plateau_y;
	char		**plateau_map;
	int			**plate_int;
	int			piece_x;
	int			piece_y;
	int			round;
	char		**figure_map;
	int			heat_number;

}				t_map;

void			get_plateau(t_map *map);
void			get_map(t_map *map);

void			get_player(t_map *map);
void			get_piece(t_map *map);
void			get_figure(t_map *map);

void			int_map_int(t_map *map);
void			fill_map_int(t_map *map);
void			heat_map(t_map *map);
void			fill_heat_map(t_map *map);

#endif
