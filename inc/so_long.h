/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:02 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/26 23:03:19 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "../inc/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

// FILE parse_map.c
int		parse_map(char *map, char **tab);
int		fill_tab(char *map, char **tab, int y);
void	fill_line(char *line, char **tab, int j);
// FILE init_map.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_map(void *mlx, void *mlx_win, char **map);
// FILE get_next_line.c
char	*get_next_line(int fd);
int		has_nl(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	clean_buf(char *buf);

#endif
