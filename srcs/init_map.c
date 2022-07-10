/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:53:41 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/10 15:19:40 by olivia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * 100, y * 100);
}

void	init_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	game->dir = 'R';
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			c = game->tab[y][x];
			display_square(game, c, x, y);
			x++;
		}
		y++;
	}
}
