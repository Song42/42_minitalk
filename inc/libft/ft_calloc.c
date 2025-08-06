/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:51:35 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/02 20:12:45 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	c;

	c = '\0';
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, c, size * nmemb);
	return (ptr);
}
