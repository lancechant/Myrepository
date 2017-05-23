/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 09:21:36 by lchant            #+#    #+#             */
/*   Updated: 2017/02/23 10:09:35 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*length;
	int	count;

	count = 0;
	if (min >= max)
		return (NULL);
	length = (int*)malloc(sizeof(*length) * (max - min));
	while (min < max)
	{
		length[count] = min;
		count++;
		min++;
	}
	return (*length);
}
