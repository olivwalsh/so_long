/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/30 16:06:25 by olivia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	loop_function(t_game *g)
{
	g->mlx = mlx_init();
	g->mlx_win = mlx_new_window(g->mlx, g->width * 100, g->length * 100, "So Long");
	init_map(g);
	mlx_hook(g->mlx_win, 2, 1L << 0, &key_hook, g);
	//mlx_hook(g->mlx_win, 3, 1L << 1, &key_hook, g);
	mlx_hook(g->mlx_win, 33, 1L << 2, &sl_close, g);
	mlx_loop(g->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		return (0);
	else if (argc > 2)
		return (error());
	if (parse_map(argv[1], &game))
		loop_function(&game);
	else
		return (error());
}
