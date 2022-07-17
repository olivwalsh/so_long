/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:28:01 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/14 19:09:23 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_walkable(char c)
{
	char	*valid;
	int		i;

	i = 0;
	valid = "0CX";
	while (valid[i])
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}

char	*player_direction(char dir)
{
	if (dir == 'U')
		return ("./imgs/player/up.xpm");
	else if (dir == 'D')
		return ("./imgs/player/down.xpm");
	else if (dir == 'L')
		return ("./imgs/player/left.xpm");
	else
		return ("./imgs/player/right.xpm");
}

void	display_square(t_game *game, char c, int x, int y)
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;

	path = NULL;
	if (c == '0')
		path = "./imgs/ground.xpm";
	else if (c == '1')
		path = "./imgs/wall.xpm";
	else if (c == 'P')
		path = player_direction(game->dir);
	else if (c == 'C')
		path = "./imgs/collectible.xpm";
	else if (c == 'E')
		path = "./imgs/exit.xpm";
	else if (c == 'X')
		path = "./imgs/ennemy.xpm";
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * 100, y * 100);
	mlx_destroy_image(game->mlx, img);
}

int	move(t_game *game, int x, int y)
{
	char	*str;
	
	str = NULL;
	game->tab[y][x] = '0';
	display_square(game, game->tab[y][x], x, y);
	if (game->dir == 'R')
		x++;
	else if (game->dir == 'L')
		x--;
	else if (game->dir == 'U')
		y--;
	else if (game->dir == 'D')
		y++;
	if (game->tab[y][x] == 'X')
		return (sl_close(game));
	game->tab[y][x] = 'P';
	display_square(game, game->tab[y][x], x, y);
	game->moves++;
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, (game->width / 2) * 115, (game->length) * 110, 0x000000FF, str);
	return (1);
}

int	map_fits_screen(t_game *game)
{
	int	screen_width;
	int	screen_height;

	screen_height = 0;
	screen_width = 0;
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (game->width * 100 > screen_width || game->length * 100 > screen_height)
		return (0);
	return (1);
}
