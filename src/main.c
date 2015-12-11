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
	/*t_list	*list;*/
	int		i;

	if (ac == 2)
	{
		i = 0;
		str_pieces = ft_get_pieces(av[1]);
		ft_putstr(str_pieces);
		/*list = ft_pieces_to_list(str_pieces);*/
		/*while (i < 4)*/
		/*{*/
		/*ft_putstr((char*)list->content);*/
		/*i++;*/
		/*}*/
	}
	return (0);
}
