/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:25:41 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 15:32:27 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*find_line(int fd, char *key)
{
	char *str;

	while (1)
	{
		get_next_line(fd, &str);
		if (ft_strstr(str, key))
			break ;
		ft_strdel(&str);
	}
	return (str);
}

void		map_reader(t_map *map)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	str = find_line(map->fd, "000");
	while (i < map->map_y - 1)
	{
		ft_strcpy(map->map[i++], ft_strchr(str, ' ') + 1);
		ft_strdel(&str);
		get_next_line(map->fd, &str);
	}
	ft_strdel(&str);
	map->map[i] = NULL;
}
