/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:53:41 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/27 19:56:13 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_game	*init_game()
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->tab = NULL;
	return (game);
}

void	display_square(t_game *game, char c, int x, int y)
{
	void	*img_from_xpm;
	char	*path;
	int		img_width;
	int		img_height;
	
	path = NULL;
	if (c == '0')
		path = "./imgs/ground_small.xpm";
	else if (c == '1')
		path = "./imgs/wall2small.xpm";
	img_from_xpm = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img_from_xpm, x + 64, y + 64);
}

void	init_map(t_game *game)
{

	int		x;
	int		y;
	char 	c;
	
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[x])
		{
			c = game->tab[x][y];
			display_square(game, c, x, y);
			printf("%c ", c);
			x++;
		}
		y++;
		printf("\n");
	}
}
