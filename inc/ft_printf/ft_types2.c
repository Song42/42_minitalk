/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:04:49 by schaehun          #+#    #+#             */
/*   Updated: 2022/04/26 10:23:52 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_neg_hex(unsigned int n, char *hex)
{
	int			length;
	char		*result;
	u_int64_t	nbr;
	int			l;

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

char	*ft_checkx(char x)
{
	char	*hex;

	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	return (hex);
}

void	ft_hex(unsigned int n, char x, int *l)
{
	int			length;
	char		*result;
	char		*hex;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	hex = ft_checkx(x);
	if (!result || !hex)
		return ;
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
