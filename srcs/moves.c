/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:07 by olivia            #+#    #+#             */
/*   Updated: 2022/07/10 15:18:53 by olivia           ###   ########.fr       */
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
			if (game->tab[y][x] == 'P'
				&& (game->tab[y][x + 1] == '0' || game->tab[y][x + 1] == 'C'))
			{
				game->tab[y][x] = '0';
				game->tab[y][x + 1] = 'P';
				display_square(game, game->tab[y][x], x, y);
				display_square(game, game->tab[y][x + 1], x + 1, y);
				return (1);
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
			if (game->tab[y][x] == 'P'
				&& (game->tab[y][x - 1] == '0' || game->tab[y][x - 1] == 'C'))
			{
				game->tab[y][x] = '0';
				game->tab[y][x - 1] = 'P';
				display_square(game, game->tab[y][x], x, y);
				display_square(game, game->tab[y][x - 1], x - 1, y);
				return (1);
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
			if (game->tab[y][x] == 'P'
				&& (game->tab[y - 1][x] == '0' || game->tab[y - 1][x] == 'C'))
			{
				game->tab[y][x] = '0';
				game->tab[y - 1][x] = 'P';
				display_square(game, game->tab[y][x], x, y);
				display_square(game, game->tab[y - 1][x], x, y - 1);
				return (1);
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
			if (game->tab[y][x] == 'P'
				&& (game->tab[y + 1][x] == '0' || game->tab[y + 1][x] == 'C'))
			{
				game->tab[y][x] = '0';
				game->tab[y + 1][x] = 'P';
				display_square(game, game->tab[y][x], x, y);
				display_square(game, game->tab[y + 1][x], x, y + 1);
				return (1);
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
