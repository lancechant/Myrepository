/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:54:16 by lde-jage          #+#    #+#             */
/*   Updated: 2017/03/06 09:54:21 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_letters(char *str, int i, t_param *map)
{
	while (str[i] != '\0')
	{
		if (str[i] != map->free && str[i] != map->obs && str[i] != 10)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check(char *str, int i, t_param *map)
{
	int	r;
	int c;
	int	temp;

	c = 0;
	i++;
	temp = i;
	while (str[i] != 10)
	{
		c++;
		i++;
	}
	r = 1;
	map->col = c;
	i++;
	c = 0;
	while (str[i] != '\0')
	{
		while (str[i] != 10)
		{
			i++;
			c++;
		}
		if (map->col != c)
			return (0);
		c = 0;
		i++;
		r++;
	}
	if (r != map->row)
		return (0);
	return (ft_letters(str, temp, map));
}

void	ft_error(void)
{
	write(1, "map error\n", 10);
}

void	ft_side(t_param *map)
{
	int		side;

	if (map->max == 0)
		ft_error();
	else
	{
		side = 1;
		while (side * side != map->max)
			side++;
		print_square(map, side - 1);
	}
}

void	ft_solve(t_param *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->max = 0;
	map->row_p = 0;
	map->col_p = 0;
	while (i < map->row)
	{
		while (j < map->col)
		{
			if (map->max < ft_square_calc(map, i, j))
			{
				map->max = ft_square_calc(map, i, j);
				map->row_p = i;
				map->col_p = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_side(map);
}

void	print_square(t_param *map, int side)
{
	int		r;
	int		c;

	r = map->row_p;
	c = map->col_p;
	while (r <= map->row_p + side)
	{
		while (c <= map->col_p + side)
		{
			map->grid[r][c] = map->full;
			c++;
		}
		c = map->col_p;
		r++;
	}
	print(map);
}
