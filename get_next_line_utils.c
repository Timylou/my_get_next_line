/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:04:01 by yel-mens          #+#    #+#             */
/*   Updated: 2024/10/27 18:07:59 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_stash(char **stash)
{
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (*stash);
}

char	*ft_strjoin(char const *s1, char const *s2, int res)
{
	char	*str;
	int		len_s1;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = malloc(0);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	str = malloc(sizeof(char) * (len_s1 + res + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	i = 0;
	while (i < res)
	{
		str[i + len_s1] = s2[i];
		i++;
	}
	str[len_s1 + res] = 0;
	return (str);
}

char	*ft_select(const char *str)
{
	char	*selected;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	if (!str[i])
		i--;
	selected = malloc(sizeof(char) * (i + 1));
	if (!selected)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		selected[i] = str[i];
		if (str[i] == '\n')
		{
			selected[i + 1] = 0;
			return (selected);
		}
	}
	return (selected);
}

char	*ft_strchr(const char *str, int to_find)
{
	to_find %= 256;
	while (*str)
	{
		if (*str == to_find)
			return ((char *) str + 1);
		str++;
	}
	if (*str == to_find)
		return ((char *) str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		len_str;
	int		i;
	char	*str_cpy;

	if (!str)
		return (NULL);
	len_str = 0;
	while (str[len_str])
		len_str++;
	str_cpy = malloc(sizeof(char) * (len_str + 1));
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = 0;
	return (str_cpy);
}
