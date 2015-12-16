/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:53 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/16 18:33:51 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*str_pieces;
	char	***tab;
	int		size;

	if (ac == 2)
	{
		str_pieces = ft_get_pieces(av[1]);
		if (ft_check_last_nl(str_pieces))
			return (0);
		tab = ft_stock_pieces(str_pieces);
		size = ft_count_pieces(str_pieces);
		while (size--)
			ft_print_tab(*tab++, 4);
	}
	return (0);
}
