/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:46:27 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/28 13:57:53 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# define PLAYER -4
# define ENEMY 0
# define EMPTY_FIELD 500

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
	int			start_x;
	int			start_y;
	int			round;
	char		**figure_map;
	int			heat_number;
	int			l_sum;
	int			return_x;
	int			return_y;
	int			coincidence;
	int			coincidence_enemy;
	char		*piece_str;
}				t_map;

void			get_plateau(t_map *map);
void			get_map(t_map *map);
void			game_start(t_map *map);
void			get_player(t_map *map);
void			get_piece(t_map *map);
void			get_figure(t_map *map);
void			int_map_int(t_map *map);
void			fill_map_int(t_map *map);
void			heat_map(t_map *map);
void			fill_heat_map(t_map *map);
void			move(t_map *map);
void			small_move(t_map *map);
void			lowest_summ(t_map *map, int start_x, int start_y);
void			check_figure(t_map *map);

#endif
