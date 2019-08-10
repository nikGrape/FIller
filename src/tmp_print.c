/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:09:34 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/09 18:24:56 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	tmp_print(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
			ft_printf("%2d ", map->map[i][j++]);
		ft_printf("\n");
		i++;
	}
	i = 0;
	ft_printf("\n\n");
	while (map->token[i])
		ft_printf("%s\n", map->token[i++]);
	ft_printf("x - %d, y - %d\n", map->token_x, map->token_y);
}
