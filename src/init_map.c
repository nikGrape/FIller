/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:13:13 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/10 17:23:53 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_player(t_map *map)
{
	char *str;

	str = find_line(map->fd, "exec p");
	if (ft_strstr(str, "1"))
		map->player = 'O';
	else
		map->player = 'X';
	ft_strdel(&str);
}

static void		get_map_xy(t_map *map)
{
	char	*str;

	str = find_line(map->fd, "Plateau");
	map->map_y = ft_atoi(ft_strchr(str, ' '));
	map->map_x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

t_map			*init_map(int fd)
{
	t_map	*map;
	int		y;

	map = (t_map *)malloc(sizeof(t_map));
	map->fd = fd;
	get_player(map);
	get_map_xy(map);
	map->map = (int **)malloc(sizeof(int *) * map->map_y);
	y = 0;
	while (y < map->map_y)
		map->map[y++] = (int *)malloc(sizeof(int) * map->map_x);
	return (map);
}
