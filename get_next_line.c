/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:03:49 by yel-mens          #+#    #+#             */
/*   Updated: 2024/10/27 18:05:30 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*temp;
	char		buffer[BUFFER_SIZE];
	int			res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	res = ft_read(fd, buffer, &stash);
	while (res > 0 || stash)
	{
		temp = stash;
		stash = ft_strjoin(temp, buffer, res);
		free(temp);
		if (!stash)
			return (NULL);
		if (!ft_strchr(stash, '\n'))
		{
			res = read(fd, buffer, BUFFER_SIZE);
			if (res < 1)
				ft_free_stash(&stash);
			continue ;
		}
		temp = ft_select(stash);
		stash = ft_linedel(stash);
		return (temp);
	}
	return (ft_free_stash(&stash));
}

char	*ft_linedel(char *str)
{
	int	i;
	int	line;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	line = i;
	while (str[i])
	{
		str[i - line] = str[i];
		i++;
	}
	str[i - line] = str[i];
	return (str);
}

int ft_read(int fd, char buffer[BUFFER_SIZE], char **stash)
{
	int			res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (!(*stash) && res > 0)
		*stash = malloc(0);
	return (res);
}
