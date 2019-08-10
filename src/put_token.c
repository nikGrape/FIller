/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:59:41 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/09 20:46:25 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		token_sum(t_map *map, int y, int x)
{
	int sum;
	int i;
	int j;

	sum = 0;
	i = 0;
	while (i < map->token_y)
	{
		j = 0;
		while (j < map->token_x)
		{
			if (map->map[i + y][j + x] != -5 && map->token[i][j] == '*')
				sum += map->map[i + y][j + x];
			j++;
		}
		i++;
	}
	return (sum);
}

int		colision_check(t_map *map, int y, int x)
{
	int i;
	int j;
	int colisions;

	colisions = 0;
	i = 0;
	while (i < map->token_y)
	{
		j = 0;
		while (j < map->token_x)
		{
			if (map->map[i + y][j + x] == -5 && map->token[i][j] == '*')
				colisions++;
			if (map->map[i + y][j + x] == 0 && map->token[i][j] == '*')
				return (0);
			j++;
		}
		if (colisions > 1)
			return (0);
		i++;
	}
	return (colisions);
}

void	put_token(t_map *map)
{
	int y;
	int x;
	int res_x;
	int res_y;
	int sum;
	int min;

	y = 0;
	min = 900;
	while (y + map->token_y <= map->map_y)
	{
		x = 0;
		while (x + map->token_x <= map->map_x)
		{
			if (colision_check(map, y, x) == 1)
			{
				sum = token_sum(map, y, x);
				if (sum <= min)
				{
					min = sum;
					res_x = x;
					res_y = y;
				}
			}
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", res_y, res_x);
}
