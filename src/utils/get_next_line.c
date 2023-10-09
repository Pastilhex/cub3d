/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoaoale <joeoalme@studet.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:42:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 17:18:06 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_gnl
{
	char	*line;
	char	*temp;
	long	read;
	long	index;
	long	s_buff;
	long	size_line;
}	t_gnl;

char	*get_line(char *line, char *buffer, long size_buf, long *size_line)
{
	t_gnl	info;

	info.size_line = -1;
	info.index = -1;
	info.s_buff = -1;
	info.line = line;
	*size_line += size_buf;
	line = malloc(*size_line + 1 * sizeof(char));
	if (line)
	{
		line[*size_line] = 0;
		while (info.line && info.line[++info.size_line])
			line[++info.index] = info.line[info.size_line];
		info.size_line = -1;
		while (buffer && buffer[++info.size_line])
		{
			if (info.size_line < size_buf)
				line[++info.index] = buffer[info.size_line];
			else
				buffer[++info.s_buff] = buffer[info.size_line];
			buffer[info.size_line] = 0;
		}
	}
	free(info.line);
	return (line);
}

void	get_next_line_while(t_gnl *d, int fd, char *buf)
{
	if (!buf[0] || !d->s_buff)
		d->s_buff = read(fd, buf, BUFFER_SIZE);
	d->index = d->s_buff;
	if (d->s_buff > 0)
	{
		d->s_buff = 0;
		while (buf[d->s_buff] && buf[d->s_buff] != '\n')
			d->s_buff++;
		d->index = (d->index == d->s_buff);
		d->s_buff += buf[d->s_buff] == '\n';
		d->line = get_line(d->line, buf, d->s_buff, &d->size_line);
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	t_gnl		d;

	d.line = NULL;
	d.s_buff = 0;
	d.index = 1;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	while (buf[d.s_buff])
		d.s_buff++;
	d.size_line = 0;
	while (d.index > 0)
	{
		get_next_line_while(&d, fd, buf);
	}
	return (d.line);
}
