/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:11:05 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/15 15:17:38 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void	map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			ft_error("Error\nl7iiit makaynch");
		i++;
	}
	while (game->map[j])
	{
		if (game->map[j][0] != '1' || game->map[j][game->column - 2] != '1')
			ft_error("Error\nl7iiit makaynch");
		j++;
	}
	i = 0;
	while (game->map[j - 1][i])
	{
		if (game->map[j - 1][i] != '1')
			ft_error("Error\nl7iiit makaynch");
		i++;
	}
}

void	map_shape(t_game *game)
{
	size_t	i;
	size_t	w_len;

	i = 0;
	w_len = game->column - 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != w_len)
			ft_error("Error\nwrong shape");
		i++;
	}
}

void	elem_count(t_game *game)
{
	int	i;
	int	j;

	game->elem_0 = 0;
	game->elem_1 = 0;
	game->elem_c = 0;
	game->elem_e = 0;
	game->elem_p = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		ft_while1(game, i, j);
	}
	if (game->elem_c == 0)
		ft_error("Error\nNo collectabels");
	else if (game->elem_e == 0)
		ft_error("Error\nNo Exit");
	else if (game->elem_p == 0)
		ft_error("Error\nNo Player");
	else if (game->elem_p > 1)
		ft_error("Error\nMulti Players");
}

void	ft_while1(t_game *game, int i, int j)
{
	while (game->map[i][++j])
	{
		if (game->map[i][j] == 'C')
			game->elem_c++;
		else if (game->map[i][j] == 'E')
			game->elem_e++;
		else if (game->map[i][j] == 'P')
			game->elem_p++;
		else if (game->map[i][j] == '1')
			game->elem_1++;
		else if (game->map[i][j] == '0')
			game->elem_0++;
		else
			ft_error("Error\nUndefined Element");
	}
}

void	ft_map(t_game *game, char *file)
{
	ft_check_file(file, ".ber");
	read_map(game, file);
	map_walls(game);
	map_shape(game);
	elem_count(game);
}
