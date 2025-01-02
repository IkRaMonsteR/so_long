/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:41:58 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/23 12:14:23 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *string);
char	*ft_line(char *string);
char	*ft_new_string(char *string);
char	*ft_free(char **str);
char	*gnl_strdup(char *s);

#endif
