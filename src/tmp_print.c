/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:09:34 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/10 17:43:33 by vinograd         ###   ########.fr       */
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
		{
			if (i == map->res_y && j == map->res_x)
				ft_printf("{yellow}%2c{eoc}", 'm');
			else if (map->map[i][j] == ME)
				ft_printf("{green}%2c{eoc}", 'M');
			else if (map->map[i][j] == ENEMY)
				ft_printf("{red}%2c{eoc}", 'E');
			else
				ft_printf("%2d", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
