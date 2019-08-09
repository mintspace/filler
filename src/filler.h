/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:46:27 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/08 14:55:24 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_map
{
	int			fd;
	char		player; /** x or O **/
	int			plateau_x;
	int			plateau_y;
	char		**plateau_map;
	int			piece_x;
	int			piece_y;
	char		**figure_map;

}				t_map;

#endif
