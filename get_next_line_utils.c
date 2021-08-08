/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:55:26 by yubae             #+#    #+#             */
/*   Updated: 2021/02/17 21:38:25 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dst == 0 || src == 0)
		return (0);
	if (size != 0)
	{
		while (i + 1 < size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i > size)
		return (ft_strlen(src) + size);
	else
	{
		while (src[j] && i + j + 1 < size)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (ft_strlen(src) + i);
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!(p = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(p, s1, s1_len + 1);
	ft_strlcat(p, s2, s1_len + s2_len + 1);
	return (p);
}

char		*ft_strdup(const char *s)
{
	char	*p;
	int		len;
	int		i;

	len = ft_strlen(s);
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
