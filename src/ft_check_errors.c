/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:04:32 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/29 15:06:35 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_check_shape(char *str_piece)
{
	int		i;

	i = 0;
	if ((ft_strlen(str_piece) / 5) != 4)
		return (1);
	while (i < 20)
	{
		if (i % 5 == 4 && str_piece[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_nb_hash(char *str_piece)
{
	int		i;
	int		count;
	char	symb;

	i = 0;
	count = 0;
	symb = '#';
	while (i < 20)
		if (str_piece[i++] == symb)
			count++;
	if (count != 4)
		return (1);
	else
		return (0);
}

int		ft_check_last_nl(char *str_pieces)
{
	int	size;

	size = ft_strlen(str_pieces) - 1;
	if (str_pieces[size] == '\n' && str_pieces[size - 1] == '\n')
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

int		ft_isempty(char *str_pieces)
{
	if (ft_strcmp(str_pieces, "") == 0)
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}
