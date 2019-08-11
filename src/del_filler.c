/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 20:08:04 by Nik               #+#    #+#             */
/*   Updated: 2019/08/10 12:38:35 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	del_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->map_y)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	del_token(t_map *map)
{
	int i;

	i = 0;
	while (map->token[i])
		ft_strdel(&map->token[i++]);
	free(map->token);
}
