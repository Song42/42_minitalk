/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:33:50 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/17 14:46:10 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_neg_hex(unsigned long long n, char *hex)
{
	int				length;
	char			*result;
	unsigned int	nbr;
	int				l;

	length = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!result)
		return (0);
	nbr = 4294967295 + n + 1;
	while (nbr != 0)
	{
		result[length++] = hex[(nbr % 16)];
		nbr /= 16;
	}
	l = length;
	while (--length >= 0)
		write(1, &result[length], 1);
	return (l);
}

void	ft_pointer_hex(unsigned long long n, int *l)
{
	int		length;
	char	*result;
	char	*hex;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!result)
		return ;
	hex = "0123456789abcdef";
	length = 0;
	if (n <= 0)
	{
		free(result);
		*l = ft_neg_hex(n, hex);
		return ;
	}
	while (n != 0)
	{
		result[length++] = hex[(n % 16)];
		n /= 16;
	}
	*l = length;
	while (--length >= 0)
		write(1, &result[length], 1);
	free(result);
}

int	ft_pointer(unsigned long long ptr)
{
	int	l;

	write(1, "0x", 2);
	ft_pointer_hex(ptr, &l);
	return (l + 2);
}
