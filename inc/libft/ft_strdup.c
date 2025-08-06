/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:06:57 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/08 14:59:53 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*dup;

	str = (char *) s;
	dup = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dup)
		return (0);
	ft_strcpy(dup, str);
	return (dup);
}
