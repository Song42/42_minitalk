/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:04:31 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/16 18:30:55 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_integer(long n)
{
	int		length;
	char	*result;
	int		l;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!result)
		return (0);
	length = 0;
	if (n == 0)
		write(1, "0", 1);
	l = ft_intlen(n);
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	while (n != 0)
	{
		result[length++] = n % 10 + '0';
		n /= 10;
	}
	while (--length >= 0)
		write(1, &result[length], 1);
	free(result);
	return (l);
}

int	ft_unsigned(unsigned int n)
{
	int		length;
	char	*result;
	int		l;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!result)
		return (0);
	length = 0;
	l = ft_intlen(n);
	if (n == 0)
		write(1, "0", 1);
	while (n != 0)
	{
		result[length] = n % 10 + '0';
		n /= 10;
		length++;
	}
	while (--length >= 0)
		write(1, &result[length], 1);
	free(result);
	return (l);
}

unsigned int	ft_intlen(long n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
