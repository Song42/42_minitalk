/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:36:00 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/24 16:37:20 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			bad_signal();
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			bad_signal();
	}
	usleep(20000);
}

int	send_to_server(char *s, int pid)
{
	int					i;
	int					bit_count;
	unsigned int		c;
	unsigned char		character;

	i = 0;
	c = 0x80;
	while (s[i])
	{
		character = s[i];
		bit_count = 0;
		while (++bit_count < 9)
		{
			send_bit(pid, character & c);
			character = character << 1;
		}
		i++;
	}
	return (1);
}

void	send_length(int length, int pid)
{
	int				i;
	unsigned int	c;

	i = 0;
	c = 0x8000;
	while (i < 16)
	{
		send_bit(pid, length & c);
		length = length << 1;
		i++;
	}
}

void	send_termination(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			bad_signal();
		usleep(20000);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("[-] unknown command. ");
		ft_printf("did you mean ./client [pid] [message] ?\n");
		return (127);
	}
	if (check_pid(argv[1]) == 1)
	{
		ft_printf("[-] bad pid\n");
		return (130);
	}
	set_sighandler();
	send_length(ft_strlen(argv[2]), ft_atoi(argv[1]));
	send_to_server(argv[2], ft_atoi(argv[1]));
	send_termination(ft_atoi(argv[1]));
	sleep(3);
}
