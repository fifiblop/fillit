/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:07:07 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/26 12:53:34 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_check_errors(char *str_piece)
{
	if (ft_check_shape(str_piece) || ft_check_dothash(str_piece) ||
		ft_check_nb_hash(str_piece) || ft_match_invalid(str_piece) ||
		ft_match_invalid2(str_piece) || ft_match_pieces(str_piece))
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

int		ft_check_nl(char nl)
{
	if (nl != '\n')
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

char	*ft_get_pieces(char *filename)
{
	int		fd;
	int		ret;
	char	buf[21];
	char	*pieces;

	pieces = "";
	ret = 0;
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, buf, 20)))
	{
		buf[ret] = '\0';
		if (ft_check_errors(buf))
			return ("");
		pieces = ft_strjoin(pieces, buf);
		if ((ret = read(fd, buf, 1)))
		{
			buf[ret] = '\0';
			if (ft_check_nl(*buf))
				return ("");
			pieces = ft_strjoin(pieces, buf);
		}
	}
	close(fd);
	return (pieces);
}
