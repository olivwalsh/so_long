/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:03:21 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/10 19:18:09 by olivia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	get_map_length(char *map_path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	fill_tab(char *map_path, t_game *game)
{
	char	*line;
	int		fd;
	int		j;
	int		y;

	y = 0;
	game->tab = malloc(sizeof(char *) * (get_map_length(map_path) + 1));
	if (!game->tab)
		return (0);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		game->tab[y] = malloc(sizeof(char) * (j + 1));
		if (!game->tab[y] || !fill_line(line, &game->tab[y], j))
			return (parsing_error(line, game->tab, y));
		free(line);
		line = get_next_line(fd);
		y++;
	}
	game->tab[y] = NULL;
	return (1);
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
		while (game->tab[y][x])
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
	if (!is_file(argv))
		return (0);
	if (!fill_tab(argv, game) || !check_line_len(game))
		return (0);
	if (in_map(game, 'P') != 1 || in_map(game, 'E') != 1 || !in_map(game, 'C'))
		return (0);
	return (1);
}
