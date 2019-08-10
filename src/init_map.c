/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:13:13 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/09 20:48:32 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_player(t_map *map)
{
	char *str;

	str = find_line(map->fd, "p1");
	if (ft_strstr(str, "vinograd"))
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
	//map->player = 'O';
	get_map_xy(map);
	map->map = (int **)malloc(sizeof(int *) * map->map_y);
	y = 0;
	while (y < map->map_y)
		map->map[y++] = (int *)malloc(sizeof(int) * map->map_x);
	return (map);
}
