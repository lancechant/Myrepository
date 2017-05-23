/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:39:48 by lde-jage          #+#    #+#             */
/*   Updated: 2017/03/07 12:39:51 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**alloc_map(char *str, int i, t_param *map)
{
	char	**temp;
	int		j;
	int		k;

	temp = (char **)malloc(sizeof(char *) * map->row);
	if (temp == NULL)
	{
		write(1, "Malloc error\n", 13);
		return (temp);
	}
	j = i;
	while (str[i] != 10)
		i++;
	i = i - j;
	k = 0;
	while (k < map->row)
	{
		temp[k] = (char *)malloc((sizeof(char) * (i + 1)));
		k++;
	}
	if (temp == NULL)
	{
		write(1, "Malloc error\n", 13);
		return (temp);
	}
	return (temp);
}

void	fr_mem(t_param *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[i] != '\0')
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}
