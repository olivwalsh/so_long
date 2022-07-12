/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:02 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/12 14:07:22 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_UP 119
# define KEY_DOWN 115

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game {
	void 	*mlx;
	void	*mlx_win;
	char	**tab;
	int		length;
	int		width;
	int		moves;
	int		collectibles;
	char	dir;
}				t_game;

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

// FILE parse_map.c
int		parse_map(char *map, t_game *game);
int		fill_tab(char *map, t_game *game);
int		fill_line(char *line, char **tab, int j);

// FILE init_map.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_map(t_game *game);
t_game	*init_game();
void	display_square(t_game *game, char c, int x, int y);

// FILE moves.c
int		key_hook(int keycode, t_game *game);

// FILE win_events.c
int		sl_close(t_game *data);
int		exit_game(t_game *game);
void	free_tab(t_game *game);

// FILE parse_utils.c
int		is_valid(char c);
int		parsing_error(char *line, t_game *game);
int		ft_strncmp(char *s1, char *s2, int n);
int		in_map(t_game *game, char c);
int		is_file(char *s);

// FILE so_long_utils.c
int		get_map_length(char *map_path);
int		move(t_game *game, int x, int y);

#endif
