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
