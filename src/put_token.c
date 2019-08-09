/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:59:41 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 17:22:44 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_board_of_values(int **nbr_map)
{
	int i;
	int j;

	i = 0;
	while (1)
	{
		j = 0;
		while ()
		{
			while (1)
				;
		}
	}
}

void		put_players_on_board(t_map *map, int **nbr_board)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '.')
				nbr_board[i][j] = (map->map[i][j] == map->player) ? -1 : 0;
			else
				nbr_board[i][j] = 142;
			j++;
		}
		i++;
	}
}

int		**init_board_of_value(t_map *map)
{
	int		**nbr_board;
	int		i;

	i = 0;
	nbr_board = (int **)malloc(sizeof(int *) * map->map_y);
	while (i < map->map_y)
		nbr_board[i++] = (int *)malloc(sizeof(int) * map->map_x);
	fill_board_of_value(map, nbr_board);
	return (nbr_board);
}

void	put_token(t_map *map)
{
	
}
