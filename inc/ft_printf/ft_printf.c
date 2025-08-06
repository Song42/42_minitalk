/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:01:45 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/16 19:23:38 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_check(const char *s, va_list vars, int *i, int *len)
{
	int	l;

	if (s[*i + 1] == 'c')
		*len += ft_putchar(va_arg(vars, int));
	if (s[*i + 1] == 's')
		*len += ft_putstr(va_arg(vars, char *));
	if (s[*i + 1] == 'p')
		*len += ft_pointer(va_arg(vars, unsigned long long));
	if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		*len += ft_integer(va_arg(vars, int));
	if (s[*i + 1] == 'u')
		*len += ft_unsigned(va_arg(vars, unsigned int));
	if (s[*i + 1] == 'x' || s[*i + 1] == 'X')
	{
		ft_hex(va_arg(vars, int), s[*i + 1], &l);
		*len += l;
	}
	if (s[*i + 1] == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		len;
	va_list	vars;

	va_start(vars, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_type_check(s, vars, &i, &len);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	va_end(vars);
	return (len);
}
