/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:02:24 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/14 10:11:22 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_get_tetri(void)
{
	char	**tetri;

	tetri = (char**)malloc(sizeof(char*) * 19);
	tetri[0] = "###...#";
	tetri[1] = "#...#..##";
	tetri[2] = "#...###";
	tetri[3] = "##..#...#";
	tetri[4] = "###..#";
	tetri[5] = "#..##...#";
	tetri[6] = "#..###";
	tetri[7] = "#...##..#";
	tetri[8] = "###.#";
	tetri[9] = "##...#...#";
	tetri[10] = "#.###";
	tetri[11] = "#...#...##";
	tetri[12] = "##.##";
	tetri[13] = "#...##...#";
	tetri[14] = "##...##";
	tetri[15] = "#..##..#";
	tetri[16] = "#...#...#...#";
	tetri[17] = "####";
	tetri[18] = "##..##";
	return (tetri);
}

char	**ft_get_name(void)
{
	char	**tetri;

	tetri = (char**)malloc(sizeof(char*) * 19);
	tetri[0] = "J1";
	tetri[1] = "J2";
	tetri[2] = "J3";
	tetri[3] = "J4";
	tetri[4] = "T1";
	tetri[5] = "T2";
	tetri[6] = "T3";
	tetri[7] = "T4";
	tetri[8] = "L1";
	tetri[9] = "L2";
	tetri[10] = "L3";
	tetri[11] = "L4";
	tetri[12] = "S1";
	tetri[13] = "s2";
	tetri[14] = "Z1";
	tetri[15] = "Z2";
	tetri[16] = "I1";
	tetri[17] = "I2";
	tetri[18] = "O1";
	return (tetri);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[j] == '\n')
			j++;
		if (s1[j] == s2[i])
		{
			i++;
			j++;
		}
		else
			return ((unsigned char)s1[j] - (unsigned char)s2[i]);
	}
	return (0);
}

int		ft_match_pieces(char *str_piece)
{
	int		j;
	int		size;
	char	**tetri;
	char	**name;
	char	*str;
	int		found;

	tetri = ft_get_tetri();
	name = ft_get_name();
	str = str_piece;
	found = 1;
	while (*str != '#')
		str++;
	j = 0;
	while (j < 19)
	{
		size = ft_strlen(tetri[j]);
		if (ft_strnequ(str, tetri[j], size) == 1)
		{
			ft_putendl(name[j]);
			found = 0;
		}
		j++;
	}
	return (found);
}
