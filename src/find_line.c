/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 19:33:44 by Nik               #+#    #+#             */
/*   Updated: 2019/08/09 19:56:51 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*find_line(int fd, char *key)
{
	char *str;

	while (get_next_line(fd, &str) > 0)
	{
		if (ft_strstr(str, key))
			break ;
		ft_strdel(&str);
	}
	return (str);
}
