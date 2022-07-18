/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:53:41 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/18 13:04:14 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_walkable(char c)
{
	char	*valid;
	int		i;

	i = 0;
	valid = "0CX";
	while (valid[i])
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	game->dir = 'R';
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			c = game->tab[y][x];
			display_square(game, c, x, y);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < game->width)
	{
		display_square(game, '0', x, y);
		x++;
	}
	mlx_string_put(game->mlx, game->mlx_win, (game->width / 2) * 105, \
		(game->length) * 110, 0x000000FF, "MOVES = 0");
}

int	fill_line(char *line, char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (!is_valid(line[i]))
			return (0);
		(*tab)[i] = line[i];
		i++;
	}
	(*tab)[i] = '\0';
	return (1);
}

int	fill_tab(t_game *game)
{
	char	*line;
	int		fd;
	int		j;
	int		y;

	y = 0;
	game->tab = malloc(sizeof(char *) * (get_map_length(game->map_path) + 1));
	if (!game->tab)
		return (0);
	fd = open(game->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		game->tab[y] = malloc(sizeof(char) * (j + 1));
		if (!game->tab[y] || !fill_line(line, &game->tab[y], j))
			return (parsing_error(line, game, y));
		free(line);
		line = get_next_line(fd);
		y++;
	}
	game->tab[y] = NULL;
	return (1);
}
