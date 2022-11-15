/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:29:08 by gusouza-          #+#    #+#             */
/*   Updated: 2022/06/27 15:40:45 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	buffer_cleaner(char	*buffer, char *raw_line, int new_line_end)
{
	int	post_line_len;

	if (raw_line[new_line_end])
	{
		post_line_len = ft_strlen(&raw_line[new_line_end]);
		ft_strlcpy(buffer, &raw_line[new_line_end], post_line_len + 1);
	}
	else
		buffer[0] = '\0';
	free(raw_line);
}

static int	line_preset(char **line, char *raw_line)
{
	int	i;

	i = 0;
	while (raw_line[i] != '\n' && raw_line[i])
		i++;
	*line = ft_calloc((i + 2), sizeof(char));
	if (raw_line[i] == '\0')
		return (i);
	return (i + 1);
}

static char	*buffer_swap(char *raw_line, char *buffer)
{
	char	*temp;

	temp = raw_line;
	raw_line = ft_strjoin(raw_line, buffer);
	free(temp);
	return (raw_line);
}

static char	*read_file(char *buffer, int fd)
{
	char	*raw_line;
	int		total_read;

	total_read = 1;
	raw_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer[0] != '\0')
		raw_line = buffer_swap(raw_line, buffer);
	while (ft_strchr(buffer, '\n') == NULL && total_read > 0)
	{
		total_read = read(fd, buffer, BUFFER_SIZE);
		if (total_read <= 0 && buffer[0] == '\0')
		{
			free(raw_line);
			return (NULL);
		}
		if (total_read != BUFFER_SIZE && total_read > 0)
			buffer[total_read] = '\0';
		if (total_read != 0)
			raw_line = buffer_swap(raw_line, buffer);
	}
	return (raw_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*raw_line;
	char		*line;
	int			new_line_end;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	raw_line = read_file(buffer, fd);
	if (raw_line == NULL)
		return (NULL);
	new_line_end = line_preset(&line, raw_line);
	ft_strlcpy(line, raw_line, new_line_end + 1);
	buffer_cleaner(buffer, raw_line, new_line_end);
	return (line);
}
