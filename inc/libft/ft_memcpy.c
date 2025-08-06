/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:18:35 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/08 14:54:57 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
