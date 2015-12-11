/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:07:50 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/10 18:49:17 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "fillit.h"

char	*ft_get_pieces(char *filename)
{
	int		fd;
	int		ret;
	char	buf[4096];
	char	*pieces;

	pieces = "";
	ret = 1;
	fd = open(filename, O_RDONLY);
	while (ret)
	{
		ret = 0;
		if ((ret = read(fd, buf, 20)))
		{
			buf[ret] = '\0';
			if (ft_check_1piece(buf))
				return ("");
			pieces = ft_strjoin(pieces, buf);
		}
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
