/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:00:40 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/10 14:44:59 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define ME		-5
# define ENEMY	0
# define DOT	-1

typedef struct
{
	int		fd;
	char	player;
	int		**map;
	int		map_x;
	int		map_y;
	char	**token;
	int		token_x;
	int		token_y;
	int		res_x;
	int		res_y;
}			t_map;

t_map		*init_map(int fd);
char		*find_line(int fd, char *key);
void		map_reader(t_map *map);
void		piece_reader(t_map *map);
void		filler(t_map *map);
void		heat_map(t_map *map);
void		put_token(t_map *map);
void		del_token(t_map *map);
void		del_map(t_map *map);
void		tmp_print(t_map *map);

#endif
