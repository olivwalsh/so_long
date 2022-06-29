/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/29 19:05:11 by olivia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error()
{
	write(2, "Error\n", 6);
	return (0);
}

int	loop_function(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * 100, game->length * 100, "So Long");
	// game->mlx_win = mlx_new_window(game->mlx, 1000, 1000, "So Long");
	init_map(game);
	mlx_hook(game->mlx_win, 2, 1L<<0, &key_hook, game);
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
