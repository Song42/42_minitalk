/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:35:52 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/24 16:42:50 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/libft/libft.h"
#include "../inc/ft_printf/ft_printf.h"

unsigned char	*g_msg;

void	send_client(int pid, int signal)
{
	if (signal == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			free(g_msg);
			ft_printf("[-] connection lost while running. ");
			ft_printf("no client.\nstopping...\n\n");
			exit(130);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			free(g_msg);
			ft_printf("[-] connection lost on the end of ");
			ft_printf("proccess. no client.\n");
		}
	}
}

int	set_size(int signal, int client_pid)
{
	static int			bit_count = 0;
	static unsigned int	length = 0;

	length |= (signal == SIGUSR1);
	bit_count += 1;
	if (bit_count > 15)
	{
		g_msg = malloc(sizeof(g_msg) * (length + 1));
		if (!g_msg)
		{
			ft_printf("[-] malloc error\n");
			exit(130);
		}
		length = 0;
		bit_count = 0;
		send_client(client_pid, 1);
		return (client_pid);
	}
	else
	{
		length = length << 1;
		send_client(client_pid, 1);
		return (0);
	}
}

int	recieve_message(int signal, int client_pid)
{
	static int				bit_count = 0;
	static int				i = 0;
	static unsigned char	character = 0;

	character |= (signal == SIGUSR1);
	if (++bit_count > 7)
	{
		g_msg[i] = character;
		if (character == '\0')
		{
			ft_printf("[+] client@%d: %s\n", client_pid, g_msg);
			free(g_msg);
			bit_count = 0;
			i = 0;
			send_client(client_pid, 2);
			return (0);
		}
		character = 0;
		bit_count = 0;
		i++;
	}
	else
		character = character << 1;
	send_client(client_pid, 1);
	return (client_pid);
}

void	signal_from_client(int signal, siginfo_t *info, void *context)
{
	int			client_pid;
	static int	mode = 0;

	(void) context;
	client_pid = info->si_pid;
	if (mode == 0)
	{
		mode = set_size(signal, client_pid);
	}
	else
	{
		if (mode != client_pid)
		{
			ft_printf("[-] conection lost. ");
			ft_printf("did you close client ?\n");
			free(g_msg);
			exit(130);
		}
		mode = recieve_message(signal, client_pid);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	(void) argv;
	if (argc != 1)
		ft_printf("warning: too many arguments\n");
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_from_client;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
	}
}
