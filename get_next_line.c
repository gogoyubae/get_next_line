/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:41:13 by yubae             #+#    #+#             */
/*   Updated: 2021/02/18 00:54:34 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*save_buf(char *save, char *buf)
{
	char		*tmp;

	if (!save)
		tmp = ft_strdup(buf);
	else
		tmp = ft_strjoin(save, buf);
	return (tmp);
}

int				find_nl(char *save)
{
	int			i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				nline(char **line, char **save, int nl)
{
	char		*tmp;
	int			len;

	if (nl == 0)
		*line = ft_strdup("");
	else
	{
		if (!(*line = malloc(sizeof(char) * (nl + 1))))
			return (-1);
		ft_strlcpy(*line, *save, nl + 1);
	}
	len = ft_strlen(*save);
	if (nl + 1 < len)
		tmp = ft_strdup(*save + nl + 1);
	else
		tmp = ft_strdup("");
	free(*save);
	*save = tmp;
	return (1);
}

int				lastline(int read_size, char **line, char **save)
{
	int			nl;

	if (read_size < 0)
		return (-1);
	if (*save && ((nl = find_nl(*save)) != -1))
		return (nline(line, save, nl));
	else if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			read_size;
	int			nl;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		tmp = save_buf(save[fd], buf);
		if (save[fd])
			free(save[fd]);
		save[fd] = tmp;
		if ((nl = find_nl(save[fd])) != -1)
			return (nline(line, &save[fd], nl));
	}
	return (lastline(read_size, line, &save[fd]));
}
