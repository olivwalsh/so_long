/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:28:01 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/18 11:39:11 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*player_direction(t_game *game)
{
	if (game->dir == 'U')
	{
		if (game->eating)
			return ("./imgs/player/eating/up.xpm");
		return ("./imgs/player/up.xpm");
	}
	else if (game->dir == 'D')
	{
		if (game->eating)
			return ("./imgs/player/eating/down.xpm");
		return ("./imgs/player/down.xpm");
	}
	else if (game->dir == 'L')
	{
		if (game->eating)
			return ("./imgs/player/eating/left.xpm");
		return ("./imgs/player/left.xpm");
	}
	else
	{
		if (game->eating)
			return ("./imgs/player/eating/right.xpm");
		return ("./imgs/player/right.xpm");
	}
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
	{
		path = player_direction(game);
		game->eating = 0;
	}
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

void	display_movescount(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	display_square(game, '0', game->width / 2, game->length);
	mlx_string_put(game->mlx, game->mlx_win, \
		(game->width / 2) * 105, (game->length) * 110, 0x000000FF, "MOVES =");
	mlx_string_put(game->mlx, game->mlx_win, \
		(game->width / 2) * 113, (game->length) * 110, 0x000000FF, str);
	free(str);
}

int	move(t_game *game, int x, int y)
{
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
	if (game->tab[y][x] == 'C')
		game->eating = 1;
	game->tab[y][x] = 'P';
	display_square(game, game->tab[y][x], x, y);
	game->moves++;
	display_movescount(game);
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
