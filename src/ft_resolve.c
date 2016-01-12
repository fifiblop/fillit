/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:19:48 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/12 10:30:09 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test_piece(char **grid, int x, int y, t_piece piece)
{
	if (grid[piece.b1.y + y][piece.b1.x + x] == '.' &&
		grid[piece.b2.y + y][piece.b2.x + x] == '.' &&
		grid[piece.b3.y + y][piece.b3.x + x] == '.' &&
		grid[piece.b4.y + y][piece.b4.x + x] == '.')
		return (1);
	else
		return (0);
}

int		ft_test_coord(int size, int x, int y, t_piece piece)
{
	if ((piece.b1.y + y) < size && (piece.b1.x + x) < size &&
		(piece.b2.y + y) < size && (piece.b2.x + x) < size &&
		(piece.b3.y + y) < size && (piece.b3.x + x) < size &&
		(piece.b4.y + y) < size && (piece.b4.x + x) < size)
		return (1);
	else
		return (0);
}

void	ft_put_piece(char **grid, int xy[2], t_piece piece, char letter)
{
	grid[piece.b1.y + xy[1]][piece.b1.x + xy[0]] = letter;
	grid[piece.b2.y + xy[1]][piece.b2.x + xy[0]] = letter;
	grid[piece.b3.y + xy[1]][piece.b3.x + xy[0]] = letter;
	grid[piece.b4.y + xy[1]][piece.b4.x + xy[0]] = letter;
}

void	ft_rm_piece(char **grid, int x, int y, t_piece piece)
{
	grid[piece.b1.y + y][piece.b1.x + x] = '.';
	grid[piece.b2.y + y][piece.b2.x + x] = '.';
	grid[piece.b3.y + y][piece.b3.x + x] = '.';
	grid[piece.b4.y + y][piece.b4.x + x] = '.';
}

int		ft_resolve(char **grid, char let, t_piece *piece, int nb_p)
{
	int		xy[3];

	xy[2] = ft_get_gridsize(grid);
	xy[1] = 0;
	while (xy[1] < xy[2])
	{
		xy[0] = 0;
		while (xy[0] < xy[2])
		{
			if (ft_test_coord(xy[2], xy[0], xy[1], *piece) &&
				ft_test_piece(grid, xy[0], xy[1], *piece))
			{
				ft_put_piece(grid, xy, *piece, let);
				if (piece->id == nb_p)
					return (1);
				if (ft_resolve(grid, let + 1, piece + 1, nb_p))
					return (1);
				else
					ft_rm_piece(grid, xy[0], xy[1], *piece);
			}
			xy[0] += 1;
		}
		xy[1] += 1;
	}
	return (0);
}
