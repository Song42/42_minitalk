/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:28:29 by schaehun          #+#    #+#             */
/*   Updated: 2021/12/10 14:20:56 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			i++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (i);
}

char	*copy_words(char const *s, int start, int end, char **split)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
	{
		j = 0;
		while (split[j])
		{
			free(split[j]);
			j++;
		}
		free(split);
		return (0);
	}
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		flag;

	if (!s)
		return (0);
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (0);
	i = -1;
	j = 0;
	flag = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || i == ft_strlen(s)) && flag >= 0)
		{
			split[j++] = copy_words(s, flag, i, split);
			flag = -1;
		}
	}
	split[j] = 0;
	return (split);
}
