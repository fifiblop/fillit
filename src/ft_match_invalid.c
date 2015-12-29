/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:49:24 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/29 16:03:05 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_get_invalid(void)
{
	char	**invalid;

	if (!(invalid = (char**)malloc(sizeof(char*) * 17)))
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
	while (j < 17)
	{
		size = ft_strlen(invalid[j]);
		if (ft_strnequ(str, invalid[j], size) == 1)
			return (1);
		j++;
	}
	return (0);
}
