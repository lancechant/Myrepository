/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 08:38:46 by lchant            #+#    #+#             */
/*   Updated: 2017/02/17 11:14:19 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		l;
	int		c;
	int		k;

	l = 0;
	c = 0;
	k = 0;
	while (l < size)
	{
		c = l + 1;
		if (tab[c] < tab[l])
		{
			k = tab[l];
			tab[l] = tab[c];
			tab[c] = k;
			c++;
		}
		else
			c++;
		l++;
	}
}
