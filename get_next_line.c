/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:38:38 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/02 17:06:53 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

char	*the_rest(char *line)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	str = ft_substr(line, (i + 1), ft_strlen(line));
	free(line);
	line = NULL;
	return (str);
}

char	*read_one_line(char **line)
{
	int	i;

	i = 0;
	if (line[0][i] == '\0')
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	return (ft_substr(*line, 0, (i + 1)));
}

char	*read_lines(int fd, char *line)
{
	char	*str;
	ssize_t	i;

	i = 1;
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line, '\n') && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			free(line);
			line = NULL;
			return (NULL);
		}
		str[i] = '\0';
		line = ft_strjoin(line, str);
	}
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_lines(fd, line);
	if (line == NULL)
		return (NULL);
	str = read_one_line(&line);
	if (str == NULL)
		return (NULL);
	line = the_rest(line);
	return (str);
}
