/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:03:21 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/06 16:12:57 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(char c)
{
	char	*valids;
	int		i;

	i = 0;
	valids = "10PCE";
	while (valids[i])
	{
		if (c == valids[i])
			return (1);
		i++;
	}
	return (0);
}

void	fill_line(char *line, char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		(*tab)[i] = line[i];
		i++;
	}
	(*tab)[i] = '\0';
}

int	parsing_error(char *line, char **tab, int y)
{
	while (y > 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
	free(line);
	return (0);
}

int	fill_tab(char *map_path, t_game *game, int y)
{
	char	*line;
	int		fd;
	int		j;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	game->tab = malloc(sizeof(char *) * (y + 1));
	if (!game->tab)
		return (0);
	y = 0;
	while (line)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		game->tab[y] = malloc(sizeof(char) * (j + 1));
		if (!game->tab[y])
			return (parsing_error(line, game->tab, y));
		fill_line(line, &game->tab[y], j);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	game->tab[y] = NULL;
	return (1);
}

int	parse_map_error(char *str)
{
	free(str);
	return (0);
}

int	check_line_len(t_game *game)
{
	int		x;
	int		y;
	int		prev_x;

	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x] && game->tab[y][x] != '\n')
			x++;
		if (y == 0)
			prev_x = x;
		if (y != 0 && prev_x != x)
			return (0);
		y++;
	}
	game->length = y;
	game->width = x;
	return (1);
}

int	parse_map(char *argv, t_game *game)
{
	int		x;
	int		y;

	if (!fill_tab(argv, game, x))
		return (0);
	if (!check_line_len(game))
		return (0);
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x] && game->tab[y][x] != '\n')
		{
			if (!is_valid(game->tab[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
