/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:29:38 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/24 16:38:41 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int	check_pid(char *str_pid)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str_pid[i])
	{
		if (ft_isdigit(str_pid[i]) == 0)
			ret = 1;
		i++;
	}
	return (ret);
}

void	bad_signal(void)
{
	ft_printf("[-] no connection. wrong pid ?\n");
	exit(130);
}

void	success_call(void)
{
	ft_printf("[+] sent\n");
	exit(0);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signal == SIGUSR1)
	{
		return ;
	}
	if (signal == SIGUSR2)
	{
		success_call();
	}
}

void	set_sighandler(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
