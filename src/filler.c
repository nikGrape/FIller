/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:39:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 15:39:03 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_map	*map;
	int		fd;
	char	*str;

	fd = open("filler.txt", O_RDONLY);
	map = get_player_and_size(fd);
	while (get_next_line(fd, &str) > 0)
	{
		filler(fd, map);
	}
	close(fd);
	tmp_print(map);
}

void	filler(int fd, t_map *map)
{
	map_reader(map);
	piece_reader(map);
}
