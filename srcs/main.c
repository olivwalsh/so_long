/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/28 19:25:45 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error()
{
	write(2, "Error\n", 6);
	return (0);
}

int	key_hook(int keycode, void *vars)
{
	(void)vars;
	printf("Hello from key_hook!\n");
	if (keycode == 2)
		printf("right\n");
	if (keycode == 1)
		printf("down");
	return (0);
}

int	loop_function(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * 100, game->length * 100, "So Long");
	// game->mlx_win = mlx_new_window(game->mlx, 1000, 1000, "So Long");
	init_map(game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_game();
	if (argc == 1)
		return (0);
	else if (argc > 2)
		return (error());
	if (parse_map(argv[1], &game))
	{
		loop_function(game);
	}
	else
		return (error());
}
