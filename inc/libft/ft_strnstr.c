/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:42:48 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/02 16:15:03 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*s;

	str = (char *) big;
	s = (char *) little;
	if (s[0] == '\0')
		return (str);
	i = 0;
	j = 0;
	while (str[i] != 0 && i < len)
	{
		while (s[j] == str[i + j] && i + j < len)
		{
			if (s[j + 1] == 0)
				return (&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
