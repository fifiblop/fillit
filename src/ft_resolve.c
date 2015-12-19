/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:52:19 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/19 16:35:38 by pdelefos         ###   ########.fr       */
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

char	**ft_resolve(t_piece *pieces)
{
	char	**grid;
	char	letter;
	int		i;
	int		size;
	int		x;
	int		y;

	(void)pieces;
	letter = 'A';
	x = 0;
	i = 0;
	size = 4;
	grid = ft_make_grid(size);
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (ft_test_coord(size, x, y, pieces[i]) && 
				ft_test_piece(grid, x, y, pieces[i]))
			{
				grid[pieces[i].b1.y + y][pieces[i].b1.x + x] = letter;
				grid[pieces[i].b2.y + y][pieces[i].b2.x + x] = letter;
				grid[pieces[i].b3.y + y][pieces[i].b3.x + x] = letter;
				grid[pieces[i].b4.y + y][pieces[i].b4.x + x] = letter;
				letter++;
				i++;
				ft_print_tab(grid, size);
				ft_putchar('\n');
			}
			y++;
		}
		x++;
	}
	return (grid);
}

int		ft_get_gridsize(char **grid)
{
	return (ft_strlen(grid[0]));
}

void	ft_put_piece(char **grid, int *tab, char letter, t_piece piece)
{
	grid[piece.b1.y + tab[1]][piece.b1.x + tab[0]] = letter;
	grid[piece.b2.y + tab[1]][piece.b2.x + tab[0]] = letter;
	grid[piece.b3.y + tab[1]][piece.b3.x + tab[0]] = letter;
	grid[piece.b4.y + tab[1]][piece.b4.x + tab[0]] = letter;
}

int		ft_recursive(char **grid, int *tab, char letter, t_piece *piece)
{
	int		size;

	size = ft_get_gridsize(grid);
	if (tab[0] == size && tab[1] == size)
		return (0);
	if (ft_test_coord(size, tab[0], tab[1], *piece) && 
		ft_test_piece(grid, tab[0], tab[1], *piece))
	{
		ft_put_piece(grid, tab, letter, *piece);
		ft_print_tab(grid, size);
		ft_putchar('\n');
		tab[0] = 0;
		tab[1] = 0;
		tab[2] -= 1;
		letter++;
		piece++;
		ft_recursive(grid, tab, letter, piece);
	}
	if (tab[0] < size)
	{
		tab[0] += 1;
		ft_recursive(grid, tab, letter, piece);
	}
	else if (tab[1] < size)
	{
		tab[0] = 0;
		tab[1] += 1;
		ft_recursive(grid, tab, letter, piece);
	}
	return (1);
}

char	**ft_all(t_piece *pieces)
{
	int		tab[3];
	char	letter;
	char	**grid;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 2;
	letter = 'A';
	grid = ft_make_grid(4);
	ft_recursive(grid, tab, letter, pieces);
	// ft_print_tab(grid, 4);
	return (grid);
}