/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 15:01:51 by lchant            #+#    #+#             */
/*   Updated: 2017/04/30 15:01:52 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

_Bool	ft_confirm_argv(int argc, char *argv[])
{
	int	i;
	int	f;

	i = 1;
	if (argc == 10)
		while (i <= 9)
		{
			f = 0;
			while (argv[i][f])
			{
				if (!((argv[i][f] >= '0' && argv[i][f] <= '9') ||
					argv[i][f] == '.'))
					return (0);
				f++;
			}
			if (f != 9)
				return (0);
			i++;
		}
	else
		return (0);
	return (1);
}

void	ft_put_into_array(char *argv[])
{
	int i;
	int f;

	i = 0;
	while (i < 9)
	{
		f = 0;
		while (f < 9)
		{
			if (argv[i + 1][f] == '.')
				g_sudoku_area[i][f] = 0;
			else
				g_sudoku_area[i][f] = argv[i + 1][f] - 48;
			f++;
		}
		i++;
	}
}

void	ft_display_array(void)
{
	int i;
	int f;

	i = 0;
	while (i < 9)
	{
		f = 0;
		while (f < 9)
		{
			g_sudoku_area[i][f] = g_sudoku_area[i][f] + 48;
			write(1, &g_sudoku_area[i][f], 1);
			if (f != 8)
				write(1, " ", 1);
			f++;
		}
		write(1, "\n", 1);
		i++;
	}
}

_Bool	ft_next_one(int row, int column)
{
	if (row == 8 && column == 8)
		return (1);
	else if (column == 8)
	{
		row++;
		column = 0;
	}
	else
		column++;
	return (ft_fill_box(row, column));
}

_Bool	ft_fill_box(int row, int column)
{
	int choices[9];
	int i;

	if (g_sudoku_area[row][column] == 0)
	{
		i = 0;
		while (i < 9)
		{
			choices[i] = ft_retrieve_compatible(row, column)[i];
			i++;
		}
		i = 0;
		while (choices[i])
		{
			g_sudoku_area[row][column] = choices[i];
			if (ft_next_one(row, column))
				return (1);
			i++;
		}
		g_sudoku_area[row][column] = 0;
	}
	else
		return (ft_next_one(row, column));
	return (0);
}
