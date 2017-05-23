/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:10:52 by lchant            #+#    #+#             */
/*   Updated: 2017/02/16 18:11:10 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strrev(char *str)
{
	int		i;
	int		n;
	char	temp;

	i = 0;
	n = ft_strlen(str);
	while (n - 1 > i)
	{
		temp = str[i];
		str[i] = str[n - 1];
		str[n - 1] = temp;
		n--;
		i++;
	}
	return (str);
}
