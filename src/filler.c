/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:39:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 00:04:08 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int		fd;
	t_map	*map;
	t_piece *piece;

	fd = open("filler.txt", O_RDONLY);
	map = map_reader(fd);
	piece = piece_reader(fd);
	close(fd);
	tmp_print(map, piece);
}
