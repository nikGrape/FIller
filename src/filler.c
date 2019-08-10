/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:39:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/09 20:56:42 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Need to improve algorithm 
** if I am O I have to get last little sum (or if I above anemy)
** if I am X I have to get first little sum
** 
** and fix del token
 */
#include "filler.h"

int		main(void)
{
	t_map	*map;
	int		fd;
	char	*str;

	//fd = open("maps/filler2.txt", O_RDONLY);
	fd = 0;
	map = init_map(fd);
	while (get_next_line(map->fd, &str) > 0)
		filler(map);
	//close(fd);
	//tmp_print(map);
}

void	filler(t_map *map)
{
	map_reader(map);
	piece_reader(map);
	heat_map(map);
	put_token(map);
	//del_token(map);
}
