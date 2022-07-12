/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:02:15 by olivia            #+#    #+#             */
/*   Updated: 2022/07/12 14:17:32 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_close(t_game *game)
{
	int	y;

	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	y = game->length;
	while (y >= 0)
	{
		free(game->tab[y]);
		y--;
	}
	free(game->tab);
	exit(0);
}

int	exit_game(t_game *game)
{
	if (in_map(game, 'C') > 0)
		return (0);
	sl_close(game);
	return (1);
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
	printf("%d\n", game->moves);
	return (1);
}
