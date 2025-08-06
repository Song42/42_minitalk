/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:25:55 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/08 18:25:40 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;
	char			*str;

	i = -1;
	j = 0;
	l = start;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	while (s[start++] && len-- > 0)
		j++;
	str = malloc(j * sizeof(char) + 1);
	if (!str)
		return (0);
	while (++i < j)
		str[i] = s[l++];
	str[i] = '\0';
	return (str);
}
