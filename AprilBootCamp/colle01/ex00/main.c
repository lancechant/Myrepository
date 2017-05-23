/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:32:14 by lchant            #+#    #+#             */
/*   Updated: 2017/04/30 13:32:16 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

char	g_sudoku_area[9][9];

int		main(int argc, char *argv[])
{
	if (ft_confirm_argv(argc, argv))
	{
		ft_put_into_array(argv);
		if (ft_fill_box(0, 0))
			ft_display_array();
		else
			write(1, "Error", 5);
	}
	else
		write(1, "Error", 5);
	return (0);
}
