/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:37:28 by lchant            #+#    #+#             */
/*   Updated: 2017/04/30 13:37:29 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

_Bool	ft_compare_row(int row, int num)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if (g_sudoku_area[row][i] == num)
			return (0);
		i++;
	}
	return (1);
}

_Bool	ft_compare_column(int column, int num)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if (g_sudoku_area[i][column] == num)
			return (0);
		i++;
	}
	return (1);
}

_Bool	ft_compare_box(int row, int column, int num)
{
	int	i;
	int	f;

	f = 0;
	while (f < 3)
	{
		i = 0;
		while (i < 3)
		{
			if (g_sudoku_area[row][i + column] == num)
				return (0);
			i++;
		}
		row++;
		f++;
	}
	return (1);
}

_Bool	ft_check_compatible(int row, int column, int num)
{
	int	group_row;
	int	group_column;

	group_row = row;
	group_column = column;
	while (group_row != 0 && group_row != 3 && group_row != 6)
		group_row--;
	while (group_column != 0 && group_column != 3 && group_column != 6)
		group_column--;
	if (ft_compare_row(row, num) && ft_compare_column(column, num) &&
		ft_compare_box(group_row, group_column, num))
		return (1);
	else
		return (0);
}

char	*ft_retrieve_compatible(int row, int column)
{
	static char	suitable_numbers[9];
	int			i;
	int			f;

	i = 1;
	f = 0;
	while (i <= 9)
	{
		if (ft_check_compatible(row, column, i))
		{
			suitable_numbers[f] = i;
			f++;
		}
		i++;
	}
	while (f < 9)
	{
		suitable_numbers[f] = 0;
		f++;
	}
	return (suitable_numbers);
}
