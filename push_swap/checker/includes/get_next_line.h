/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:17:05 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 14:39:40 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_checknl(char **str, char afternl[BUFFER_SIZE], char **buff);
char			*ft_exit(char *str, char **temp);
int				ft_read(int fd, char *buff, int len);
char			*ft_strndup(char *dst, char *src, int size);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif