/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 20:05:54 by eplumeco          #+#    #+#             */
/*   Updated: 2015/12/11 12:16:27 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"

char		**ft_create_tab(char *str_piece)
{
	char	**block;
	int		size;
	int		i;
	int		x;
	int		y;

	size = 4;
	i = 0;
	y = 0;
	if (!(block = (char **)malloc(sizeof(char*) * size)))
		return (NULL);
	while (y < size)
	{
		x = 0;
		block[y] = malloc(sizeof(char *) * size);
		while (x <= size)
		{
			block[y][x++] =  str_piece[i++];
		}
		y++;
	}
	return (block);
}


int		main(void)
{
	char	*test1;
	int		size;
	char	**tab;
	int		x;

	x = 0;
	size = 4;
	test1 = "....\n....\n....\n####\n";
	ft_putendl("test pour 1 seule piece valide");
	tab = ft_create_tab(test1);
	while (x < size)
	{
		ft_putstr(tab[x]);
		x++;
	}
	return (0);
}
