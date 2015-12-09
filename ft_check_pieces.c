/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:07:58 by eplumeco          #+#    #+#             */
/*   Updated: 2015/12/09 19:49:16 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_valid_tab(char *str_piece)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (ft_strlen(str_piece) == 0)
		return (0);
	while (str_piece[i])
	{
		if (i % 5 == 4 && str_piece[i] == '\n')
		count++;
		if (count == 4 && (str_piece[i] != '\n'))
		{
			ft_putchar(str_piece[i]);
			return (0);
		}
		i++;
	}
	return (1);
}


int		main(void)
{
	char	*test1;
	char	*test2;

	test1 = "...#\n...#\n...#\n...#\n";
		ft_putnbr(check_valid_tab(test1));
		ft_putchar('\n');
	test2 = "...#\n...#\n...#\n...#\n\n....\n....\n....\n####\n";
		ft_putnbr(check_valid_tab(test2));
		return (0);
}
