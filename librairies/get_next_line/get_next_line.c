/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:20:47 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/23 12:16:10 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *string)
{
	char	*buf;
	int		read_bytes;

	read_bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free(&string), NULL);
	while (read_bytes > 0 && !gnl_strchr(string, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (ft_free(&string), NULL);
		}
		buf[read_bytes] = '\0';
		string = gnl_strjoin(string, buf);
		if (!string)
		{
			ft_free(&string);
			return (free(buf), NULL);
		}
	}
	return (free(buf), string);
}

char	*ft_line(char *string)
{
	int		i;
	char	*line;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_string(char *string)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\0')
	{
		ft_free(&string);
		return (NULL);
	}
	new_string = (char *)malloc((gnl_strlen(string) - i + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	j = 0;
	i++;
	while (string[i])
		new_string[j++] = string[i++];
	new_string[j] = '\0';
	ft_free(&string);
	return (new_string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!string || !gnl_strchr(string, '\n'))
		string = ft_read(fd, string);
	if (!string)
		return (NULL);
	line = ft_line(string);
	if (!line)
		return (ft_free(&string));
	string = ft_new_string(string);
	return (line);
}
