/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:38:26 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/06 17:06:55 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_calloc(size_t nmemb, size_t size);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*get_next_line(int fd);
#endif
