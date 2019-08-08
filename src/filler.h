/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:00:40 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 00:00:43 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct
{
	int		fd;
	char	player;
	int		x;
	int		y;
	char	**map;
}			t_map;

typedef struct
{
	int		x;
	int		y;
	char	**piece;
}			t_piece;

t_map		*map_reader(int fd);
t_piece		*piece_reader(int fd);
void	tmp_print(t_map *map, t_piece *piece);

#endif
