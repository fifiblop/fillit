/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:07:37 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/16 18:22:29 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_get_tetri2(void)
{
	char	**tetri;

	tetri = (char**)malloc(sizeof(char*) * 19);
	tetri[0] = "###...#";
	tetri[1] = ".#...#..##";
	tetri[2] = "#...###";
	tetri[3] = "##..#...#";
	tetri[4] = "###..#";
	tetri[5] = ".#..##...#";
	tetri[6] = ".#..###";
	tetri[7] = "#...##..#";
	tetri[8] = "###.#";
	tetri[9] = "##...#...#";
	tetri[10] = "..#.###";
	tetri[11] = "#...#...##";
	tetri[12] = ".##.##";
	tetri[13] = "#...##...#";
	tetri[14] = "##...##";
	tetri[15] = ".#..##..#";
	tetri[16] = "#...#...#...#";
	tetri[17] = "####";
	tetri[18] = "##..##";
	return (tetri);
}

char	**ft_to_tab(char *piece)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		size;

	i = 0;
	k = 0;
	size = ft_strlen(piece);
	tab = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(char) * 4);
		while (j < 4)
		{
			if (k < size)
				tab[i][j++] = piece[k++];
			else
				tab[i][j++] = '.';
		}
		i++;
	}
	return (tab);
}

int		ft_count_pieces(char *str_pieces)
{
	return ((ft_strlen(str_pieces) + 1) / 21);
}

void	ft_print_tab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(tab[i++]);
}

char	***ft_stock_pieces(char *str_pieces)
{
	int		i;
	int		nb_pieces;
	char	***tab;
	char	**tetri;
	char	*piece;

	i = 0;
	nb_pieces = ft_count_pieces(str_pieces);
	tetri = ft_get_tetri2();
	tab = (char***)malloc(sizeof(char**) * nb_pieces);
	while (i < nb_pieces)
	{
		piece = ft_strsub(str_pieces, 0, 20);
		tab[i++] = ft_to_tab(tetri[ft_get_pattern(piece)]);
		free(piece);
		str_pieces += 21;
	}
	return (tab);
}
