/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:52:19 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/17 20:10:47 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_make_grid(int size)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = (char*)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
		i++;
	}
	return (tab);
}

char	**ft_resolve(t_piece *pieces)
{
	char	**grid;
	char	letter;
	int		i;
	// int		j;
	int		size;

	(void)pieces;
	letter = 'A';
	i = 0;
	size = 4;
	grid = ft_make_grid(size);
	if (grid[ft_atoi(pieces[0].b1.x)][ft_atoi(pieces[0].b1.y)] == '.'  &&
		grid[ft_atoi(pieces[0].b2.x)][ft_atoi(pieces[0].b2.y)] == '.'  &&
		grid[ft_atoi(pieces[0].b3.x)][ft_atoi(pieces[0].b3.y)] == '.'  &&
		grid[ft_atoi(pieces[0].b4.x)][ft_atoi(pieces[0].b4.y)] == '.')
	{
		grid[ft_atoi(pieces[0].b1.x)][ft_atoi(pieces[0].b1.y)] = '#';
		grid[ft_atoi(pieces[0].b2.x)][ft_atoi(pieces[0].b2.y)] = '#';
		grid[ft_atoi(pieces[0].b3.x)][ft_atoi(pieces[0].b3.y)] = '#';
		grid[ft_atoi(pieces[0].b4.x)][ft_atoi(pieces[0].b4.y)] = '#';
	}
	return (grid);
}
