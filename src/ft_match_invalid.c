/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:49:24 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/26 12:38:32 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_get_invalid(void)
{
	char	**invalid;

	if (!(invalid = (char**)malloc(sizeof(char*) * 20)))
		return (NULL);
	invalid[0] = "###\n#";
	invalid[1] = "##\n##";
	invalid[2] = "#\n###";
	invalid[3] = "##\n#...\n#";
	invalid[4] = "#\n##..\n.#";
	invalid[5] = "#.\n..##\n#";
	invalid[6] = "#\n...#\n##";
	invalid[7] = "#\n...#\n...#\n#";
	invalid[8] = "#\n..##\n#";
	invalid[9] = "##\n...#\n#";
	invalid[10] = "##\n#..#";
	invalid[11] = "#\n#..#\n...#";
	invalid[12] = "##\n#.#";
	invalid[13] = "#\n##.#";
	invalid[14] = "#.##\n#";
	invalid[15] = "#.#\n##";
	invalid[16] = "#\n#..#\n#";
	invalid[17] = "#\n#.##";
	invalid[18] = "#\n...#\n#...\n#";
	invalid[19] = "##.#\n#";
	return (invalid);
}

char	**ft_get_invalid2(void)
{
	char	**invalid;

	if (!(invalid = (char**)malloc(sizeof(char*) * 8)))
		return (NULL);
	invalid[0] = "#...\n#..#\n#";
	invalid[1] = "#\n#...\n#...\n#";
	invalid[2] = "#..#\n##";
	invalid[3] = "#\n...#\n#..#";
	invalid[4] = "#\n##..\n#";
	invalid[5] = "#..#\n#...\n#";
	invalid[6] = "#\n#...\n##";
	invalid[7] = "#..#\n#..#";
	return (invalid);
}

int		ft_match_invalid(char *str_piece)
{
	int		j;
	int		size;
	char	**invalid;
	char	*str;

	invalid = ft_get_invalid();
	str = str_piece;
	while (*str != '#')
		str++;
	j = 0;
	while (j < 20)
	{
		size = ft_strlen(invalid[j]);
		if (ft_strnequ(str, invalid[j], size) == 1)
			return (1);
		j++;
	}
	return (0);
}

int		ft_match_invalid2(char *str_piece)
{
	int		j;
	int		size;
	char	**invalid;
	char	*str;

	invalid = ft_get_invalid2();
	str = str_piece;
	while (*str != '#')
		str++;
	j = 0;
	while (j < 8)
	{
		size = ft_strlen(invalid[j]);
		if (ft_strnequ(str, invalid[j], size) == 1)
			return (1);
		j++;
	}
	return (0);
}
