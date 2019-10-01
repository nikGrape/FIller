/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:13:55 by Nik               #+#    #+#             */
/*   Updated: 2019/10/01 14:51:02 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define MAX(A, B) ((A) > (B) ? (A) : (B))

void	dot_encircle(t_map *map, int y, int x)
{
	int value;

	value = map->map[y][x] + 1;
	if (y > 0)
	{
		if (map->map[y - 1][x] == DOT)
			map->map[y - 1][x] = value;
		if (map->map[y - 1][x + 1] == DOT && x < map->map_x - 1)
			map->map[y - 1][x + 1] = value;
		if (map->map[y - 1][x - 1] == DOT && x > 0)
			map->map[y - 1][x - 1] = value;
	}
	if (map->map[y][x + 1] == DOT && x < map->map_x - 1)
		map->map[y][x + 1] = value;
	if (map->map[y][x - 1] == DOT && x != 0)
		map->map[y][x - 1] = value;
	if (y < map->map_y - 1)
	{
		if (map->map[y + 1][x] == DOT)
			map->map[y + 1][x] = value;
		if (map->map[y + 1][x + 1] == DOT && x < map->map_x - 1)
			map->map[y + 1][x + 1] = value;
		if (map->map[y + 1][x - 1] == DOT && x > 0)
			map->map[y + 1][x - 1] = value;
	}
}

void	heat_map(t_map *map)
{
	int y;
	int x;
	int val;
	int max;

	max = MAX(map->map_x, map->map_y);
	val = 0;
	while (val < max)
	{
		y = 0;
		while (y < map->map_y)
		{
			x = 0;
			while (x < map->map_x)
			{
				if (map->map[y][x] == val)
					dot_encircle(map, y, x);
				x++;
			}
			y++;
		}
		val++;
	}
}
