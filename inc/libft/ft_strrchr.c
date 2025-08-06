/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:36:26 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/02 15:53:21 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	chr;

	if (c > 256)
		c -= 256;
	str = (char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (str[i] != 0)
		i++;
	while (i--)
	{
		if (str[i] == c)
			return (&str[i]);
	}
	if (!chr)
		return (&str[ft_strlen(s)]);
	return (0);
}
