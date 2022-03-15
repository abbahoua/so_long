/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:41:33 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/08 15:53:06 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int	ft_open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nfile doesn't exist");
	return (fd);
}

void	ft_check_file(char *file, char *str)
{
	int	i;
	int	j;

	i = ft_strlen(file) - ft_strlen(str);
	if (i <= 0 || file[i] != '.')
		ft_error("Error\nWrong file name");
	j = 0;
	while (file[i + j] && str[j])
	{
		if (file[i + j] != str[j])
			ft_error("Error\n");
		j++;
	}
}

void	read_map(t_game	*game, char *file)
{
	char	*line;
	char	*buf;
	int		fd;

	line = NULL;
	fd = ft_open_file(file);
	buf = get_next_line(fd);
	if (!buf)
		ft_error("Error\nMap khawya\n");
	game->column = ft_strlen(buf);
	game->lines = 1;
	condition(game, line, buf, fd);
}

void	condition(t_game *game, char *line, char *buf, int fd)
{
	while (buf != NULL)
	{
		if (buf[0] == '\n')
		{
			free(buf);
			printf("Error\nthere is an empty line in your map\n");
			exit(1);
		}
		line = ft_strjoin(line, buf);
		free(buf);
		buf = get_next_line(fd);
		game->lines++;
	}
	free(buf);
	if (line[ft_strlen(line) - 1] == '\n')
		ft_error("Error\nthere is an empty line in your map\n");
	game->map = ft_split(line, '\n');
	free(line);
}
