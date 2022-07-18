/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:02 by owalsh            #+#    #+#             */
/*   Updated: 2022/07/18 13:15:19 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_UP 119
# define KEY_DOWN 115

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game {
	char	*map_path;
	void	*mlx;
	void	*mlx_win;
	char	**tab;
	int		length;
	int		width;
	int		moves;
	int		collectibles;
	char	dir;
	int		eating;
}				t_game;

/*
*** FILE parse.c
*/
int		parse_map(t_game *game);
int		is_file(char *s);
int		is_rectangle(t_game *game);
int		is_framed(t_game *game);
/*
*** FILE init.c
*/
void	init_map(t_game *game);
int		is_walkable(char c);
int		fill_line(char *line, char **tab, int j);
int		fill_tab(t_game *game);
/*
*** FILE display.c
*/
char	*player_direction(t_game *game);
void	display_square(t_game *game, char c, int x, int y);
int		move(t_game *game, int x, int y);
int		map_fits_screen(t_game *game);
/*
*** FILE moves.c
*/
int		key_hook(int keycode, t_game *game);
/*
*** FILE utils.c
*/
int		is_valid(char c);
int		in_map(t_game *game, char c);
void	*ft_memset(void *s, int c, size_t n);
int		get_map_length(char *map_path);
int		ft_strncmp(char *s1, char *s2, int n);
/*
*** FILE exit.c
*/
int		parsing_error(char *line, t_game *game, int index);
int		sl_close(t_game *game);
void	free_tab(t_game *game, int index);
int		exit_game(t_game *game);
// FILE utils/ft_itoa.c
char	*ft_itoa(int n);

#endif
