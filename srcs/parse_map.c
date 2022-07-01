/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:03:21 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/01 18:06:16 by owalsh           ###   ########.fr       */
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

int	fill_tab(char *map, t_game *game, int y)
{
	char	*line;
	int		fd;
	int		j;

	fd = open(map, O_RDONLY);
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

int	parse_map(char *map, t_game *game)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	int		prev_x;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		while (line[x] && line[x] != '\n')
		{
			if (!is_valid(line[x]))
			{
				free(line);
				return (0);
			}
			x++;
		}
		if (y == 0)
			prev_x = x;
		if (y != 0 && prev_x != x)
			return (0);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	game->length = y;
	game->width = x;
	return (fill_tab(map, game, x));
}
