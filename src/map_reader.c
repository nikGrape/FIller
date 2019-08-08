/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:25:41 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/07 23:57:10 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_player(t_map *map)
{
	char *str;

	get_next_line(map->fd, &str);
	if (ft_strstr(str, "vinograd"))
		map->player = 'O';
	else
		map->player = 'X';
	ft_strdel(&str);
}

static void		get_xy(t_map *map)
{
	char	*str;

	while (1)
	{
		get_next_line(map->fd, &str);
		if (ft_strstr(str, "Plateau"))
			break ;
		ft_strdel(&str);
	}
	map->y = ft_atoi(ft_strchr(str, ' '));
	map->x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

t_map		*map_reader(int fd)
{
	t_map	*map;
	char	*str;
	char	*p;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	map->fd = fd;
	get_player(map);
	get_xy(map);
	map->map = (char **)malloc(sizeof(char *) * (map->y + 1));
	get_next_line(fd, &str);
	ft_strdel(&str);
	i = 0;
	while (i < map->y)
	{
		map->map[i] = ft_strnew(map->x);
		get_next_line(fd, &str);
		ft_strcpy(map->map[i++], ft_strchr(str, ' ') + 1);
		ft_strdel(&str);
	}
	map->map[i] = NULL;
	return (map);
}
