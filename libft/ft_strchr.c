/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudaa <lboudaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:08:00 by lboudaa           #+#    #+#             */
/*   Updated: 2014/04/14 17:55:07 by lboudaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	while (1)
	{
		if (s[i] == c)
		{
			p = &((char *)s)[i];
			return (p);
		}
		if (!s[i])
			break ;
		i++;
	}
	return (0);
}
