/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:05:01 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/08 19:04:53 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	return (keycode);
}

void	move_right(t_game *game)
{
	if (game->map[game->player_x][game->player_y + 1] == '0' ||
		game->map[game->player_x][game->player_y + 1] == 'C')
	{
		if (game->map[game->player_x][game->player_y + 1] == 'C')
			game->elem_c--;
		game->map[game->player_x][game->player_y + 1] = 'P';
		game->map[game->player_x][game->player_y] = '0';
		game->move++;
		write_step(game);
		ft_drawing(game);
	}
	else if (game->map[game->player_x][game->player_y + 1] == 'E' &&
		game->elem_c == 0)
		ft_error("YOU WIN\n");
}

void	move_left(t_game *game)
{
	if (game->map[game->player_x][game->player_y - 1] == '0' ||
		game->map[game->player_x][game->player_y - 1] == 'C')
	{
		if (game->map[game->player_x][game->player_y - 1] == 'C')
			game->elem_c--;
		game->map[game->player_x][game->player_y - 1] = 'P';
		game->map[game->player_x][game->player_y] = '0';
		game->move++;
		write_step(game);
		ft_drawing(game);
	}
	else if (game->map[game->player_x][game->player_y - 1] == 'E' &&
		game->elem_c == 0)
		ft_error("YOU WIN\n");
}

void	move_up(t_game *game)
{
	if (game->map[game->player_x - 1][game->player_y] == '0' ||
		game->map[game->player_x - 1][game->player_y] == 'C')
	{
		if (game->map[game->player_x - 1][game->player_y] == 'C')
			game->elem_c--;
		game->map[game->player_x - 1][game->player_y] = 'P';
		game->map[game->player_x][game->player_y] = '0';
		game->move++;
		write_step(game);
		ft_drawing(game);
	}
	else if (game->map[game->player_x - 1][game->player_y] == 'E' &&
		game->elem_c == 0)
		ft_error("YOU WIN\n");
}

void	move_down(t_game *game)
{
	if (game->map[game->player_x + 1][game->player_y] == '0' ||
		game->map[game->player_x + 1][game->player_y] == 'C')
	{
		if (game->map[game->player_x + 1][game->player_y] == 'C')
			game->elem_c--;
		game->map[game->player_x + 1][game->player_y] = 'P';
		game->map[game->player_x][game->player_y] = '0';
		game->move++;
		write_step(game);
		ft_drawing(game);
	}
	else if (game->map[game->player_x + 1][game->player_y] == 'E' &&
		game->elem_c == 0)
		ft_error("YOU WIN\n");
}
