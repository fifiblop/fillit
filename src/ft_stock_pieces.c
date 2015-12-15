/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:07:37 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/15 22:21:59 by pdelefos         ###   ########.fr       */
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

int			ft_count_pieces(char *str_pieces)
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

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node)
	{
		if (content == NULL)
		{
			node->content = NULL;
			node->content_size = 0;
		}
		else
		{
			node->content = (void*)malloc(content_size);
			if (node->content == NULL)
				return (NULL);
			ft_putendl("hello");
			node->content = (void*)content;
			node->content_size = content_size;
		}
		node->next = NULL;
	}
	return (node);
}

void	ft_lst_pback(t_list *alst, void *cnt, size_t cnt_size)
{
	if (alst != NULL)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = ft_lstnew(cnt, cnt_size);
	}
	else
		alst = ft_lstnew(cnt, cnt_size);
}

t_list		*ft_stock_pieces(char *str_pieces)
{
	int		nb_pieces;
	t_list	*list;
	int		i;
	char	*piece;
	char	**tetri;
	char	**tmp;

	list = NULL;
	i = 0;
	tetri = ft_get_tetri2();
	nb_pieces = ft_count_pieces(str_pieces);
	while (i < nb_pieces)
	{
		piece = ft_strsub(str_pieces, 0, 20);
		tmp = ft_to_tab(tetri[ft_get_pattern(piece)]);
		ft_lst_pback(list, tmp, 4);
		free(piece);
		free(tmp);
		str_pieces += 21;
		i++;
	}
	return (list);
}
