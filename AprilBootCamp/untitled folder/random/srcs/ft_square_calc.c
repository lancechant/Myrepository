/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:04:05 by lde-jage          #+#    #+#             */
/*   Updated: 2017/03/06 12:04:08 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_row(t_param *map, int r, int ct, int rt)
{
	while (rt >= r)
	{
		if (map->grid[rt][ct] == map->obs)
			return (0);
		rt--;
	}
	return (1);
}

int		ft_col(t_param *map, int rt, int c, int ct)
{
	while (ct >= c)
	{
		if (map->grid[rt][ct] == map->obs)
		{
			return (0);
		}
		ct--;
	}
	return (1);
}

int		ft_square_calc(t_param *map, int r, int c)
{
	int		square;
	int		rt;
	int		ct;

	ct = c;
	rt = r;
	square = 1;
	if (map->grid[r][c] == map->obs)
		return (0);
	else if (r == map->row - 1 && c == map->col - 1)
		return (1);
	while (rt < map->row && ct < map->col)
	{
		if (rt < map->row && ct < map->col && ft_row(map, r, ct, rt) != 0 &&
			ft_col(map, rt, c, ct) != 0)
		{
			square = ((ct - c) + 1) * ((rt - r) + 1);
			ct++;
			rt++;
		}
		else
			return (square);
	}
	return (square);
}

void	print(t_param *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[i] != '\0')
	{
		while (map->grid[i][j] != '\0')
		{
			write(1, &map->grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
