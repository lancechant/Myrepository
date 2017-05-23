/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:20:24 by lchant            #+#    #+#             */
/*   Updated: 2017/02/23 12:26:14 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*length;

	i = 0;
	if (min >= max)
	{
		range[0] = NULL;
		return (0);
	}
	length = (int*)malloc(sizeof(*length) * (max - min));
	while (min < max)
	{
		length[i] = min;
		i++;
		min++;
	}
	*range = length;
	return (i);
}
