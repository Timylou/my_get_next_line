/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:03:49 by yel-mens          #+#    #+#             */
/*   Updated: 2024/10/30 19:17:25 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*temp;
	char		*buffer;
	int			res;

	res = ft_read(fd, &buffer, &stash[fd]);
	while (res > 0 || stash[fd])
	{
		temp = stash[fd];
		stash[fd] = ft_strjoin(temp, buffer, res);
		free(temp);
		free(buffer);
		if (!stash[fd])
			return (NULL);
		if (!ft_strchr(stash[fd]) && res > 0)
		{
			res = ft_read(fd, &buffer, &stash[fd]);
			continue ;
		}
		temp = ft_select(stash[fd]);
		stash[fd] = ft_linedel(stash[fd]);
		return (temp);
	}
	ft_free_stash(&stash[fd], &buffer, res);
	return (NULL);
}

char	*ft_linedel(char *str)
{
	int	i;
	int	line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = i;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
	{
		str[i - line - 1] = str[i];
		i++;
	}
	str[i - line - 1] = '\0';
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	ft_read(int fd, char **buffer, char **stash)
{
	int			res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-10);
	*buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!(*buffer))
		return (0);
	res = read(fd, *buffer, BUFFER_SIZE);
	if (res < 0)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
		return (0);
	}
	if (!(*stash) && res > 0)
	{
		*stash = malloc(sizeof(char));
		(*stash)[0] = 0;
	}
	return (res);
}
