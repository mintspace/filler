/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:42:07 by dbubnov           #+#    #+#             */
/*   Updated: 2019/08/08 00:30:49 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

// void	player_read()

int		main(void)
{
	int fd;

	fd = open("./filler.txt", O_RDONLY);

	ft_printf("%s\n", "abc");


	return (0);
}
