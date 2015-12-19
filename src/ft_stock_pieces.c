/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:07:37 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/19 11:59:22 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char		**ft_get_tetri2(void)
{
	char	**tetri;

	tetri = (char**)malloc(sizeof(char*) * 19);
	tetri[0] = "00102021";
	tetri[1] = "10111202";
	tetri[2] = "00011121";
	tetri[3] = "00100102";
	tetri[4] = "00102011";
	tetri[5] = "10011112";
	tetri[6] = "10011121";
	tetri[7] = "00011102";
	tetri[8] = "00102001";
	tetri[9] = "00101112";
	tetri[10] = "20011121";
	tetri[11] = "00010212";
	tetri[12] = "10200111";
	tetri[13] = "00011112";
	tetri[14] = "00101121";
	tetri[15] = "10011102";
	tetri[16] = "00010203";
	tetri[17] = "00102030";
	tetri[18] = "00100111";
	return (tetri);
}

int			ft_count_pieces(char *str_pieces)
{
	return ((ft_strlen(str_pieces) + 1) / 21);
}

void		ft_print_tab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(tab[i++]);
}

static int	ft_ctoi(char c)
{
	if (c >= '0' && c <= '9')
		c -= 48;
	return (c);
}

t_piece		*ft_stock_pieces(char *str_pieces)
{
	int		i;
	int		nb_pieces;
	t_piece	*tab;
	t_piece	piece;
	char	**tetri;

	i = 0;
	nb_pieces = ft_count_pieces(str_pieces);
	tetri = ft_get_tetri2();
	tab = (t_piece*)malloc(sizeof(t_piece) * nb_pieces);
	while (i < nb_pieces)
	{
		piece.b1.x = ft_ctoi(tetri[ft_get_pattern(str_pieces)][0]);
		piece.b1.y = ft_ctoi(tetri[ft_get_pattern(str_pieces)][1]);
		piece.b2.x = ft_ctoi(tetri[ft_get_pattern(str_pieces)][2]);
		piece.b2.y = ft_ctoi(tetri[ft_get_pattern(str_pieces)][3]);
		piece.b3.x = ft_ctoi(tetri[ft_get_pattern(str_pieces)][4]);
		piece.b3.y = ft_ctoi(tetri[ft_get_pattern(str_pieces)][5]);
		piece.b4.x = ft_ctoi(tetri[ft_get_pattern(str_pieces)][6]);
		piece.b4.y = ft_ctoi(tetri[ft_get_pattern(str_pieces)][7]);
		tab[i++] = piece;
		str_pieces += 21;
	}
	return (tab);
}
