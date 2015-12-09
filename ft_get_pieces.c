/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:07:50 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/09 20:41:57 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

t_list		ft_get_pieces(char *filename)
{
	int		fd;
	int		ret;
	char	buf[4096];
	t_list	*list;

	list = NULL;
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, buf, 4096)))
	{
		buf[ret] = '\0';
		ft_lst_pback(&list, ft_strdup(buf));
	}
	close(fd);
	return (list);
}


