/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:09:34 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 00:01:12 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	tmp_print(t_map *map, t_piece *piece)
{
	int		i;
	char	*str;

	i = 0;
	while (map->map[i])
		ft_printf("%s\n", map->map[i++]);
	ft_printf("\nplayer - %c\nx - %d, y - %d\n", map->player, map->x, map->y);
	i = 0;
	ft_printf("\n\n");
	while (piece->piece[i])
		ft_printf("%s\n", piece->piece[i++]);
	ft_printf("x - %d, y - %d\n", piece->x, piece->y);
}
