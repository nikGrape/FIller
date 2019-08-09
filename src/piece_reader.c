/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 23:17:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 13:48:40 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_token_xy(t_map *map)
{
	char *str;

	get_next_line(map->fd, &str);
	map->token_y = ft_atoi(ft_strchr(str, ' '));
	map->token_x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

void			piece_reader(t_map *map)
{
	char		*str;
	int			i;

	get_token_xy(map);
	map->token = (char **)malloc(sizeof(char *) * (map->token_y + 1));
	i = 0;
	while (i < map->token_y)
	{
		map->token[i] = ft_strnew(map->token_x);
		get_next_line(map->fd, &str);
		ft_strcpy(map->token[i++], str);
		ft_strdel(&str);
	}
	map->token[i] = NULL;
}
