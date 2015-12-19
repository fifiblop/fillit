/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:53 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/19 14:55:40 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*str_pieces;
	t_piece	*tab;
	char	**grid;

	if (ac == 2)
	{
		str_pieces = ft_get_pieces(av[1]);
		if (ft_check_last_nl(str_pieces))
			return (0);
		tab = ft_stock_pieces(str_pieces);
		// grid = ft_resolve(tab);
		grid = ft_all(tab);
	}
	else
		ft_putendl("error");
	return (0);
}
