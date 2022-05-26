/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/26 17:12:01 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error()
{
	ft_putstr("Error\n");
}

int	main(int argc, char **argv)
{
	void	*ptr;
	void	*mlx_win;


	(void)ptr;
	(void)mlx_win;


	ptr = mlx_init();
	mlx_win = mlx_new_window(ptr, 1920, 1080, "Hello world!");
	mlx_loop(ptr);
	
	if (argc == 2)
	{
		(void)argv;
	}
	else
		error();

	return (0);
}
