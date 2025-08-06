/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:50:10 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/08 14:57:24 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n < 1)
		return (0);
	i = 0;
	while (i < n - 1 && str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			break ;
	}
	return (str1[i] - str2[i]);
}
