/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:09:34 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 14:34:17 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	tmp_print(t_map *map)
{
	int		i;
	char	*str;

	i = 0;
	while (map->map[i])
		ft_printf("%s\n", map->map[i++]);
	ft_printf("\nplayer - %c\nx - %d, y - %d\n", map->player, map->map_x, map->map_y);
	i = 0;
	ft_printf("\n\n");
	while (map->token[i])
		ft_printf("%s\n", map->token[i++]);
	ft_printf("x - %d, y - %d\n", map->token_x, map->token_y);
}
