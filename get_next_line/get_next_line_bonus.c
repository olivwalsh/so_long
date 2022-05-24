/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/17 17:17:53 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int				ret;
	char			*line;

	if ((fd < 0 || fd >= FOPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	line = NULL;
	line = ft_strjoin(line, buf[fd]);
	while (ret && !has_nl(line))
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		if (ret)
		{
			buf[fd][ret] = '\0';
			line = ft_strjoin(line, buf[fd]);
		}
	}
	clean_buf(buf[fd]);
	return (line);
}
