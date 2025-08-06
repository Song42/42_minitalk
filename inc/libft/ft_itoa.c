/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:42:33 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/06 16:35:32 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_intlen(int n)
{
	unsigned int	len;
	unsigned int	num;

	len = 0;
	if (n < 0)
	{
		len++;
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		len++;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	num;
	char			*str;

	i = ft_intlen(n);
	str = malloc((ft_intlen(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
