/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:00:40 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/08 14:35:41 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct
{
	int		fd;
	char	player;
	char	**map;
	int		map_x;
	int		map_y;
	char	**token;
	int		token_x;
	int		token_y;
}			t_map;

t_map		*get_player_and_size(int fd);
void		map_reader(t_map *map);
void		piece_reader(t_map *map);
void		tmp_print(t_map *map);
void		filler(int fd, t_map *map);

#endif
