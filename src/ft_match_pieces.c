/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:02:24 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/23 14:20:23 by pdelefos         ###   ########.fr       */
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

int		ft_strncmp2(const char *s1, const char *s2, size_t n)
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

int		ft_strnequ2(char const *s1, char const *s2, size_t n)
{
	if (ft_strncmp2(s1, s2, n) == 0)
		return (1);
	return (0);
}

int		ft_get_pattern(char *str_piece)
{
	int		j;
	int		size;
	char	**tetri;
	char	*str;
	int		found;

	tetri = ft_get_tetri();
	str = str_piece;
	found = -1;
	while (*str != '#')
		str++;
	j = 0;
	while (j < 19)
	{
		size = ft_strlen(tetri[j]);
		if (ft_strnequ2(str, tetri[j], size) == 1)
			found = j;
		j++;
	}
	return (found);
}

int		ft_match_pieces(char *str_piece)
{
	int		j;
	int		size;
	char	**tetri;
	char	*str;
	int		found;

	tetri = ft_get_tetri();
	str = str_piece;
	found = 1;
	while (*str != '#')
		str++;
	j = 0;
	while (j < 19)
	{
		size = ft_strlen(tetri[j]);
		if (ft_strnequ2(str, tetri[j], size) == 1)
			found = 0;
		j++;
	}
	return (found);
}
