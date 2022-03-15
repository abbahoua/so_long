/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:54 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/08 14:15:19 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void	ft_get_path(t_game *game)
{
	int	img;

	game->player = mlx_xpm_file_to_image(game->mlx,
			"./img/mario.xpm", &img, &img);
	if (!game->player)
		ft_error("Error\nwrong path");
	game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &img, &img);
	if (!game->wall)
		ft_error("Error\nwrong path");
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm", &img, &img);
	if (!game->floor)
		ft_error("Error\nwrong path");
	game->collec = mlx_xpm_file_to_image(game->mlx,
			"./img/mashroom.xpm", &img, &img);
	if (!game->collec)
		ft_error("Error\nwrong path");
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/door.xpm", &img, &img);
	if (!game->exit)
		ft_error("Error\nwrong path");
	ft_drawing(game);
}

void	ft_drawing(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		ft_while(game, j, i);
	}
}

void	ft_while(t_game *game, int j, int i)
{
	while (game->map[i][++j])
	{
		if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall,
				game->x * j, game->y * i);
		else if (game->map[i][j] == '0' || game->map[i][j] == 'P' ||
			game->map[i][j] == 'C' || game->map[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->x * j, game->y * i);
		if (game->map[i][j] == 'P')
		{
			game->player_x = i;
			game->player_y = j;
			mlx_put_image_to_window(game->mlx, game->win, game->player,
				game->x * j, game->y * i);
		}
		if (game->map[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit,
				game->x * j, game->y * i);
		if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->collec,
				game->x * j, game->y * i);
	}
}
