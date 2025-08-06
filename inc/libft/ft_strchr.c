/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:01:42 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/02 16:13:54 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	chr;

	i = 0;
	str = (char *) s;
	chr = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	if (!chr)
		return (&str[ft_strlen(s)]);
	return (0);
}
