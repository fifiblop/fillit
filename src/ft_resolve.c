/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:52:19 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/23 12:31:01 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_make_grid(int size)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = (char*)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

int		ft_get_gridsize(char **grid)
{
	return (ft_strlen(grid[0]));
}

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

void	ft_rm_piece(char **grid, int x, int y, t_piece piece)
{
	grid[piece.b1.y + y][piece.b1.x + x] = '.';
	grid[piece.b2.y + y][piece.b2.x + x] = '.';
	grid[piece.b3.y + y][piece.b3.x + x] = '.';
	grid[piece.b4.y + y][piece.b4.x + x] = '.';
}

int		ft_resolve(char **grid, char letter, t_piece *piece, int nb_pieces)
{
	int		size;
	int		x;
	int		y;

	size = ft_get_gridsize(grid);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_test_coord(size, x, y, *piece) &&
				ft_test_piece(grid, x, y, *piece))
			{
				grid[piece->b1.y + y][piece->b1.x + x] = letter;
				grid[piece->b2.y + y][piece->b2.x + x] = letter;
				grid[piece->b3.y + y][piece->b3.x + x] = letter;
				grid[piece->b4.y + y][piece->b4.x + x] = letter;
				if (piece->id == nb_pieces)
					return (1);
				if (ft_resolve(grid, letter + 1, piece + 1, nb_pieces))
					return (1);
				else
					ft_rm_piece(grid, x, y, *piece);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**ft_all(t_piece *pieces, int nb_pieces)
{
	char	letter;
	char	**grid;
	int		size;

	letter = 'A';
	size = 2;
	grid = ft_make_grid(size);
	while (ft_resolve(grid, letter, pieces, nb_pieces) != 1)
		grid = ft_make_grid(++size);
	return (grid);
}
