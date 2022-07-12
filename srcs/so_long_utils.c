/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:30:02 by olivia            #+#    #+#             */
/*   Updated: 2022/07/11 19:43:52 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_length(char *map_path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
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
	game->tab[y][x] = 'P';
	display_square(game, game->tab[y][x], x, y);
	game->moves++;
	ft_printf("%d\n", game->moves);
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
