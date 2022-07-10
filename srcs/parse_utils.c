/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivia <olivia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:57:15 by olivia            #+#    #+#             */
/*   Updated: 2022/07/10 14:02:24 by olivia           ###   ########.fr       */
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

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	in_map(t_game *game, char c)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (game->tab[y])
	{
		x = 0;
		while (game->tab[y][x])
		{
			if (game->tab[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	return (i);
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
