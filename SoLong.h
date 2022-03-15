/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:37:44 by abbahoua          #+#    #+#             */
/*   Updated: 2022/03/08 19:01:22 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE	1

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdio.h> 
# include <fcntl.h> 
# include <errno.h>
# include <mlx.h>

typedef struct s_game
{
	char	**map;
	int		lines;
	int		column;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*floor;
	void	*collec;
	void	*exit;
	int		elem_p;
	int		elem_e;
	int		elem_c;
	int		elem_0;
	int		elem_1;
	int		move;
}		t_game;

void	ft_putstr(char *s);
void	ft_error(char *str);
void	map_walls(t_game *game);
void	map_shape(t_game *game);
void	elem_count(t_game *game);
void	map_composent(t_game *game);
void	ft_check_file(char *file, char *str);
void	ft_drawing(t_game *game);
void	ft_get_path(t_game *game);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);
void	read_map(t_game	*game, char *file);
void	ft_map(t_game *game, char *file);
int		file_end(char *s);
char	*get_next_line(int fd);
int		key_hook(int keycode, t_game *game);
char	*ft_strcat(char *dst, char *src);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	ft_while(t_game *game, int j, int i);
void	ft_while1(t_game *game, int i, int j);
void	condition(t_game *game, char *line, char *buf, int fd);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	write_step(t_game *game);

#endif