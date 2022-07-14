/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:07 by olivia            #+#    #+#             */
/*   Updated: 2022/07/14 18:14:47 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game)
{
	int		x;
	int		y;

	game->dir = 'R';
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			if (game->tab[y][x] == 'P')
			{
				if (is_walkable(game->tab[y][x + 1]))
					return (move(game, x, y));
				else if (game->tab[y][x + 1] == 'E' && !in_map(game, 'C'))
				{
					move(game, x, y);
					return (exit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	move_left(t_game *game)
{
	int		x;
	int		y;

	game->dir = 'L';
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			if (game->tab[y][x] == 'P')
			{
				if (is_walkable(game->tab[y][x - 1]))
					return (move(game, x, y));
				else if (game->tab[y][x - 1] == 'E' && !in_map(game, 'C'))
				{
					move(game, x, y);
					return (exit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	move_up(t_game *game)
{
	int		x;
	int		y;

	game->dir = 'U';
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			if (game->tab[y][x] == 'P')
			{
				if (is_walkable(game->tab[y - 1][x]))
					return (move(game, x, y));
				else if (game->tab[y - 1][x] == 'E' && !in_map(game, 'C'))
				{
					move(game, x, y);
					return (exit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	move_down(t_game *game)
{
	int		x;
	int		y;

	game->dir = 'D';
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			if (game->tab[y][x] == 'P')
			{
				if (is_walkable(game->tab[y + 1][x]))
					return (move(game, x, y));
				else if (game->tab[y + 1][x] == 'E' && !in_map(game, 'C'))
				{
					move(game, x, y);
					return (exit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
		return (move_right(game));
	else if (keycode == KEY_LEFT)
		return (move_left(game));
	else if (keycode == KEY_UP)
		return (move_up(game));
	else if (keycode == KEY_DOWN)
		return (move_down(game));
	else if (keycode == 65307)
		return (sl_close(game));
	return (0);
}
