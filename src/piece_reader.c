/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 23:17:45 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/07 23:57:51 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_xy(int fd, t_piece *piece)
{
	char *str;

	get_next_line(fd, &str);
	piece->y = ft_atoi(ft_strchr(str, ' '));
	piece->x = ft_atoi(ft_strrchr(str, ' '));
	ft_strdel(&str);
}

t_piece		*piece_reader(int fd)
{
	t_piece		*piece;
	char		*str;
	int			i;

	piece = (t_piece *)malloc(sizeof(t_piece));
	get_xy(fd, piece);
	piece->piece = (char **)malloc(sizeof(char *) * (piece->y + 1));
	i = 0;
	while (i < piece->y)
	{
		piece->piece[i] = ft_strnew(piece->x);
		get_next_line(fd, &str);
		ft_strcpy(piece->piece[i++], str);
		ft_strdel(&str);
	}
	piece->piece[i] = NULL;
	return (piece);
}
