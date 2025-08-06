/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:36:58 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/13 11:09:49 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		send_to_server(char *s, int pid);
void	send_length(int length, int pid);
void	send_termination(int pid);
void	success_call(void);
void	handler(int signal, siginfo_t *info, void *context);
void	set_sighandler(void);
void	bad_signal(void);
void	send_bit(int pid, int bit);
int		check_pid(char *str_pid);

#endif
