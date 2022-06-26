/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/26 23:08:56 by owalsh           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	char		**tab;

	tab = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 2)
		return (error());
	if (parse_map(argv[1], tab))
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		init_map(mlx, mlx_win, tab);
		mlx_loop(mlx);
	}
	else
		return (error());
}
