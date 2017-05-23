/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 07:44:32 by lchant            #+#    #+#             */
/*   Updated: 2017/02/17 07:44:35 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		count;
	int		num;
	int		neg;

	num = 0;
	count = 0;
	neg = 0;
	if (str[count] == '-')
		neg = 1;
	if (!(str[count] && (str[count] >= '0') && (str[count] <= '9')))
		count++;
	while (str[count] && (str[count] >= '0') && (str[count] <= '9'))
	{
		num *= 10;
		num += (int)str[count] - '0';
		count++;
	}
	if (neg == 1)
		return (-num);
	else
		return (num);
}
