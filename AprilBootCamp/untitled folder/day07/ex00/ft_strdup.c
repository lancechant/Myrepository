/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:44:53 by lchant            #+#    #+#             */
/*   Updated: 2017/02/22 17:13:26 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*d;

	d = malloc(ft_strlen (str) + 1);
	if (d == NULL)
		return (NULL);
		strcpy (d, s)
	return (d);
}

int	main(void)
{
	printf("%s\n", ft_strlen("test"));
}