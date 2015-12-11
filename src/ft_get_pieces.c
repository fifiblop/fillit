/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:07:07 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/11 19:10:53 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char		*ft_get_pieces(char *filename)
{
	int		fd;
	int		ret;
	char	buf[4096];
	char	*pieces;

	pieces = "";
	ret = 1;
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, buf, 20)))
	{
		buf[ret] = '\0';
		if (ft_check_1piece(buf))
			return ("");
		pieces = ft_strjoin(pieces, buf);
		if ((ret = read(fd, buf, 1)))
		{
			buf[ret] = '\0';
			if (*buf != '\n')
				return ("");
			pieces = ft_strjoin(pieces, buf);
		}
	}
	close(fd);
	return (pieces);
}

static char	**ft_create_tab(char *str_pieces)
{
	char	**block;
	int		size;
	int		x;
	int		y;

	size = 4;
	y = 0;
	if (!(block = (char **)malloc(sizeof(char*) * size)))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(block[y] = malloc(sizeof(char *) * size)))
			return (NULL);
		while (x <= size)
		{
			block[y][x++] = *str_pieces++;
		}
		y++;
	}
	return (block);
}

t_list		*ft_pieces_to_list(char *str_pieces)
{
	t_list	**list;
	/*int		i;*/

	list = NULL;
	ft_create_tab(str_pieces);
	/*ft_lst_pback(list, ft_create_tab(str_pieces), 0);*/
	/*i = 0;*/
	/*while (i++ < 21 && *str_pieces)*/
	/*str_pieces++;*/
	return (*list);
}
