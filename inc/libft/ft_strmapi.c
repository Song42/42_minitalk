/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:49:34 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/03 20:25:28 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	d = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!d)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		d[i] = (char) s[i];
		i++;
	}
	d[i] = '\0';
	i = 0;
	while (d[i] != 0)
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	return (d);
}
