/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifiblop <fifiblop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:52:19 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/18 22:28:52 by fifiblop         ###   ########.fr       */
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
		tab[i] = (char*)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
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

void	ft_ft(t_piece *pieces)
{
	char	**grid;
	int		size;
	int		i;

	size = 4;
	i = 0;
	while (i < 19)
	{
		grid = ft_make_grid(size);
		grid[pieces[i].b1.y][pieces[i].b1.x] = '#';
		grid[pieces[i].b2.y][pieces[i].b2.x] = '#';
		grid[pieces[i].b3.y][pieces[i].b3.x] = '#';
		grid[pieces[i].b4.y][pieces[i].b4.x] = '#';
		ft_print_tab(grid, size);
		ft_putchar('\n');
		i++;
	}
}
