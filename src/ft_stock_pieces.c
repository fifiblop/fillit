/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:07:37 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/14 19:35:14 by pdelefos         ###   ########.fr       */
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
		tab[i] = (char*)malloc(sizeof(char) * 5);
		while (j < 5)
		{
			if (j == 4)
				tab[i][j++] = '\n';
			else
			{
				if (k < size)
					tab[i][j++] = piece[k++];
				else
					tab[i][j++] = '.';
			}
		}
		i++;
	}
	return (tab);
}

int		main(void)
{
	char	**tab;
	char	**tetri;
	int		i;
	int		j;

	j = 0;
	tetri = ft_get_tetri2();
	while (j < 19)
	{
		i = 0;
		tab = ft_to_tab(tetri[j++]);
		while (i < 4)
			ft_putstr(tab[i++]);
		ft_putchar('\n');
	}
	return (0);
}
