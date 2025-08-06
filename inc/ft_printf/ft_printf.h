/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:17:11 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/16 19:39:57 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(char const *s, ...);
unsigned int	ft_intlen(long n);
int				ft_putstr(char *s);
int				ft_putchar(int c);
int				ft_integer(long n);
int				ft_unsigned(unsigned int n);
int				ft_neg_hex(unsigned int n, char *hex);
char			*ft_checkx(char x);
void			ft_hex(unsigned int n, char x, int *l);
int				ft_pointer(unsigned long long ptr);
void			ft_type_check(const char *s, va_list vars, int *l, int *len);
void			ft_pointer_hex(unsigned long long n, int *l);
int				ft_pointer_neg_hex(unsigned long long n, char *hex);

#endif
