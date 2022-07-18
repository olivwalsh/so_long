/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:30:02 by olivia            #+#    #+#             */
/*   Updated: 2022/07/18 12:30:52 by owalsh           ###   ########.fr       */
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

void	*ft_memset(void *s, int c, size_t n)
{
	char	*i_s;
	size_t	i;

	i_s = s;
	i = 0;
	while (s && i < n)
	{
		i_s[i] = c;
		i++;
	}
	return (s);
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
