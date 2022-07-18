/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:57:15 by olivia            #+#    #+#             */
/*   Updated: 2022/07/18 12:55:29 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_game *game)
{
	if (!is_file(game->map_path))
		return (0);
	if (!fill_tab(game) || !is_rectangle(game) || !is_framed(game))
		return (0);
	if (in_map(game, 'P') != 1 || in_map(game, 'E') != 1 || !in_map(game, 'C'))
	{
		free_tab(game, game->length);
		return (0);
	}
	return (1);
}

int	is_file(char *s)
{
	int		i;
	char	*ext;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	ext = ".ber";
	i = ft_strlen(s);
	return (ft_strncmp(s + i - 4, ext, 4));
}

int	is_rectangle(t_game *game)
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
		{
			free_tab(game, get_map_length(game->map_path));
			return (0);
		}
		y++;
	}
	game->length = y;
	game->width = x;
	return (1);
}

int	is_framed(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			if (game->tab[y][x] != '1')
			{
				if (y == 0 || y == game->length - 1 \
					|| x == 0 || x == game->width - 1)
				{
					free_tab(game, game->length);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}
