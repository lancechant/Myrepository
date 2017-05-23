/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:26:13 by lchant            #+#    #+#             */
/*   Updated: 2017/03/07 08:57:55 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	openfile(int ac, char **arr, t_param *map, char str[4097])
{
	int		i;
	int		fd;

	i = 0;
	while (i < ac)
	{
		if ((fd = open(arr[i++], O_RDONLY)) == -1)
		{
			continue;
		}
		read_str(fd, str);
		i = get_map_param(str, map);
		if (ft_check(str, i, map) != 0)
		{
			map->grid = ft_map(str, i, map);
			ft_solve(map);
			close(fd);
		}
		else
			write(2, "map error\n", 10);
	}
}

int		main(int argc, char **argv)
{
	t_param		map;
	char		str[4097];
	int			i;

	if (argc < 2)
	{
		read_str(0, str);
		i = get_map_param(str, &map);
		if (ft_check(str, i, &map) != 0)
		{
			map.grid = ft_map(str, i, &map);
			ft_solve(&map);
		}
		else
			write(2, "map error\n", 10);
	}
	else
		openfile(argc, argv, &map, str);
	return (0);
}
