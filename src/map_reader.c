/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:25:41 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/09 20:53:59 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		put_players_on_board(t_map *map, int line, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			map->map[line][i] = (str[i] == map->player) ? -5 : 0;
		else
			map->map[line][i] = -1;
		i++;
	}
}

void		map_reader(t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	str = find_line(map->fd, "000");
	put_players_on_board(map, i++, ft_strchr(str, ' ') + 1);
	ft_strdel(&str);
	while (i < map->map_y)
	{
		get_next_line(map->fd, &str);
		put_players_on_board(map, i++, ft_strchr(str, ' ') + 1);
		ft_strdel(&str);
	}
}
