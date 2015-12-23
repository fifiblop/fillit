/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:53 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/23 14:40:05 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*str_pieces;
	t_piece	*tab;
	char	**grid;
	int		nb_pieces;

	if (ac == 2)
	{
		str_pieces = ft_get_pieces(av[1]);
		if (ft_isempty(str_pieces) || ft_check_last_nl(str_pieces))
			return (0);
		nb_pieces = ft_count_pieces(str_pieces);
		tab = ft_stock_pieces(str_pieces, nb_pieces);
		grid = ft_all(tab, nb_pieces);
		ft_print_grid(grid);
	}
	else
		ft_putendl("error");
	return (0);
}
