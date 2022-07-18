/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:02:15 by olivia            #+#    #+#             */
/*   Updated: 2022/07/18 13:07:32 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing_error(char *line, t_game *game, int index)
{
	free_tab(game, index);
	free(line);
	return (0);
}

int	sl_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	if (game)
	{
		free_tab(game, game->length);
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit(0);
}

void	free_tab(t_game *game, int index)
{
	int	y;

	y = 0;
	if (game->tab)
	{
		if (game->tab[y])
		{
			while (y <= index)
			{
				free(game->tab[y]);
				y++;
			}
		}
		free(game->tab);
	}
}

int	exit_game(t_game *game)
{
	if (in_map(game, 'C') > 0)
		return (0);
	sl_close(game);
	return (1);
}
