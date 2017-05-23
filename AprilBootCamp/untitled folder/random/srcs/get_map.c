/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:49:37 by lchant            #+#    #+#             */
/*   Updated: 2017/03/06 10:29:51 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		sep_param(char *str, t_param *map)
{
	int		i;
	int		j;
	char	num[10];

	i = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (j < i)
	{
		num[j] = str[j];
		j++;
	}
	num[j] = '\0';
	map->row = ft_atoi(num);
	map->free = str[j];
	map->obs = str[j + 1];
	map->full = str[j + 2];
}

char		**ft_map(char *str, int i, t_param *map)
{
	int		j;
	int		k;

	i++;
	j = 0;
	k = 0;
	map->grid = alloc_map(str, i, map);
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != '\0')
		{
			map->grid[j][k] = str[i];
			i++;
			k++;
		}
		map->grid[j][k] = '\0';
		k = 0;
		i++;
		j++;
	}
	return (map->grid);
}

void		read_str(int fd, char str[4097])
{
	int		i;

	i = read(fd, str, 4096);
	if (i <= 0)
	{
		i = errno;
		perror("error:");
	}
	str[i] = '\0';
	i = 0;
}

int			get_map_param(char *str, t_param *map)
{
	int		i;
	char	par[8];

	i = 0;
	while (str[i] != 10)
	{
		par[i] = str[i];
		i++;
	}
	par[i] = '\0';
	sep_param(par, map);
	return (i);
}
