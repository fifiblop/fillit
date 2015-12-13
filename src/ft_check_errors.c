/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:04:32 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/11 11:05:00 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_1piece(char *str_piece)
{
	int		i;

	i = 0;
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

int		ft_check_errors(char *str_piece)
{
	if (ft_check_1piece(str_piece) || ft_check_nb_hash(str_piece))
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int		ft_check_nl(char nl)
{
	if (nl != '\n')
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int		ft_check_last_nl(char *str_pieces)
{
	int	size;

	size = ft_strlen(str_pieces) - 1;
	if (str_pieces[size] == '\n' && str_pieces[size - 1] == '\n')
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
