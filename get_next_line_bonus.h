/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:35:59 by yel-mens          #+#    #+#             */
/*   Updated: 2024/10/30 19:07:22 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_free_stash(char **stash, char **buffer, int res);
char	*ft_strjoin(char const *s1, char const *s2, int res);
char	*ft_select(const char *stash);
char	*ft_strchr(const char *str);
char	*ft_strdup(const char *str);
char	*ft_linedel(char *str);
int		ft_read(int fd, char **buffer, char **stash);
#endif
