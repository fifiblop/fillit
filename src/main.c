/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:53 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/11 19:08:34 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*str_pieces;

	if (ac == 2)
	{
		str_pieces = ft_get_pieces(av[1]);
		if (ft_check_last_nl(str_pieces))		
				return (0);
		ft_putnbr(ft_match_pieces(str_pieces));
		ft_putchar('\n');
		ft_putstr(str_pieces);
	}
	return (0);
}
