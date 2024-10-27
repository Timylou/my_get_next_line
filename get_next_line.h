/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:35:59 by yel-mens          #+#    #+#             */
/*   Updated: 2024/10/27 18:05:04 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_free_stash(char **stash);
char	*ft_strjoin(char const *s1, char const *s2, int res);
char	*ft_select(const char *stash);
char	*ft_strchr(const char *str, int to_find);
char	*ft_strdup(const char *str);
char	*ft_linedel(char *str);
int     ft_read(int fd, char buffer[BUFFER_SIZE], char **stash);
#endif
