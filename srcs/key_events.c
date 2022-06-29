/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:07 by olivia            #+#    #+#             */
/*   Updated: 2022/06/29 19:05:20 by olivia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
		printf("move right\n");
	else if (keycode == KEY_LEFT)
		printf("move left\n");
	else if (keycode == KEY_UP)
		printf("move up\n");
	else if (keycode == KEY_DOWN)
		printf("move down\n");
	else if (keycode == 27)
		mlx_destroy_window(game->mlx, game->mlx_win);
	return (0);
}
