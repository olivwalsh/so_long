/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:53:41 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/26 23:12:32 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_map(void *mlx, void *mlx_win, char **map)
{
	// void	*img_from_xpm;
	// char	*path;
	// int		img_width;
	// int		img_height;
	int		x;
	int		y;

	// path = NULL;
	(void)mlx;
	(void)mlx_win;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			printf("%c ", map[x][y]);
			x++;
		}
		printf("\n");
		
	}
	// if (c == '0')
	// 	path = "./imgs/ground_small.xpm";
	// else if (c == '1')
	// 	path = "./imgs/wall2small.xpm";
	// printf("segfault before img_from_xpm\n");
	// img_from_xpm = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	// printf("segfault after img_from_xpm\n");
	// mlx_put_image_to_window(mlx, mlx_win, img_from_xpm, x, y);
	// printf("segfault after put image to window\n");
}
