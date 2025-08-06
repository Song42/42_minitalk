/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:16:29 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/06 20:20:36 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		length;
	char	result[255];
	long	nbr;

	length = 0;
	nbr = n;
	if (nbr == 0)
		write(fd, "0", 1);
	if (nbr < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}
	while (nbr != 0)
	{
		result[length] = nbr % 10 + '0';
		nbr /= 10;
		length++;
	}
	while (--length >= 0)
		write(fd, &result[length], 1);
}
