/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:53:41 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/30 17:13:11 by olivia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_square(t_game *game, char c, int x, int y)
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;

	path = NULL;
	if (c == '0')
		path = "./imgs/ground_resized.xpm";
	else if (c == '1')
		path = "./imgs/wall.xpm";
	else if (c == 'P')
		path = "./imgs/p2.xpm";
	else if (c == 'C')
		path = "./imgs/collect.xpm";
	else if (c == 'E')
		path = "./imgs/ex.xpm";
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * 100, y * 100);
}

void	init_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

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
