/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:07:50 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/10 12:47:22 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

char	*ft_get_pieces(char *filename)
{
	int		fd;
	int		ret;
	char	buf[4096];
	char	*pieces;

	pieces = "";
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, buf, 4096)))
	{
		buf[ret] = '\0';
		pieces = ft_strjoin(pieces, buf);
	}
	close(fd);
	return (pieces);
}
