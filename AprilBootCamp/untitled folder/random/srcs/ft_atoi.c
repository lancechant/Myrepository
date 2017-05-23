/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 07:24:18 by lde-jage          #+#    #+#             */
/*   Updated: 2017/03/07 07:24:25 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int i;
	int j;
	int value;
	int temp;

	i = 0;
	j = 1;
	value = 0;
	if (str[0] < 48 || str[0] > 59)
		return (0);
	while (str[i] >= 48 && str[i] <= 59)
		i++;
	value = ((int)str[0]) - 48;
	while (j < i)
	{
		temp = ((int)str[j]) - 48;
		value = (value * 10) + temp;
		j++;
	}
	return (value);
}
