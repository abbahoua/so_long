/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:47:44 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/15 15:08:41 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int	ft_exit(t_game *game)
{
	(void)game;
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.move = 0;
	if (ac != 2)
		ft_error("Error\nWrong number of arguments");
	ft_map(&game, av[1]);
	game.x = 50;
	game.y = 50;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.column - 1) * game.x,
			(game.lines - 1) * game.y, "SoLong");
	ft_get_path(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0L, ft_exit, &game);
	mlx_loop(game.mlx);
}
