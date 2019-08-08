/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:46:27 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/07 23:46:12 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_plateau_map
{
	char		player;
	int			x;
	int			y;
	char		**plateau_map;
}				t_plateau_map;

typedef struct	s_piece
{
	char		*piece_numbers;
	char		**piece_map;
}				t_piece;


#endif
