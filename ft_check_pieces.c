/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:07:58 by eplumeco          #+#    #+#             */
/*   Updated: 2015/12/10 16:36:38 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_first_tab(char *str_piece)
{
	int		i;
	int		count_n;
	int		size;

	i = 0;
	count_n = 0;
	size = ft_strlen(str_piece);
	if (size == 0)
		return (0);
	while (i < size -1)
	{
		if (i % 5 == 4 && str_piece[i] != '\n')
			return (0);
		if (str_piece[i] == '\n')
			count_n++;
		if (count_n == 4)
		{
			count_n = 0;
			if (str_piece[i + 1] != '\n')
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}


/*int		check_all_tab(char *str_piece, int count)*/
/*{*/
	/*if ()*/
/*}*/


int		main(void)
{
	char	*test1;
	char	*test2;
	char	*test3;
	char	*test4;

	test1 = "...#\n...#\n...#\n...#\n";
		ft_putendl("test pour 1 seule piece valide");
		ft_putnbr(check_first_tab(test1));
		ft_putchar('\n');

	test2 = "...#\n...#\n...#\n...#\n\n....\n....\n....\n####\n";
		ft_putendl("test pour 2 pieces valides");
		ft_putnbr(check_first_tab(test2));
		ft_putchar('\n');

	test3 = "...#\n...#\n...#\n...#\n\n....\n....\n....\n####\n\n.###\n...#\n....\n....\n\n....\n..##\n.##.\n....\n";
		ft_putendl("test pour 4 pieces valides");
		ft_putnbr(check_first_tab(test3));
		ft_putchar('\n');

	test4 = "...#\n...#\n....#\n...#\n\n....\n..\n#....#\n...#\n....\n....\n\n....\n..##\n.##.\n....\n";
		ft_putendl("test pour 4 pieces non valides");
		ft_putnbr(check_first_tab(test4));
		ft_putchar('\n');
	return (0);
}
