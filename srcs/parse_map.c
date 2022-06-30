/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:03:21 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/30 12:42:02 by owalsh           ###   ########.fr       */
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

int	fill_tab(char *map, t_game *game, int y)
{
	char	*line;
	int		fd;
	int		j;
	char	**tab;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	tab = malloc(sizeof(char *) * (y + 1));
	if (!tab)
		return (0);
	y = 0;
	while (line)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		tab[y] = malloc(sizeof(char) * (j + 1));
		if (!tab[y])
		{
			free(line);
			return (0);
		}
		fill_line(line, &tab[y], j);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	tab[y] = NULL;
	game->tab = tab;
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
