/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_and_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:13:13 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 15:57:16 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_player(t_map *map)
{
	char *str;

	get_next_line(map->fd, &str);
	if (ft_strstr(str, "vinograd"))
		map->player = 'O';
	else
		map->player = 'X';
	ft_strdel(&str);
}

static void		get_map_xy(t_map *map)
{
	char	*str;

	while (1)
	{
		get_next_line(map->fd, &str);
		if (ft_strstr(str, "Plateau"))
			break ;
		ft_strdel(&str);
	}
	map->map_y = ft_atoi(ft_strchr(str, ' '));
	map->map_x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

t_map			*get_player_and_size(int fd)
{
	t_map	*map;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	map->fd = fd;
	get_player(map);
	get_map_xy(map);
	map->map = (char **)malloc(sizeof(char *) * (map->map_y + 1));
	i = 0;
	while (i < map->map_y)
		map->map[i++] = ft_strnew(map->map_x);
	return (map);
}
