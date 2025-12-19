/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:13:47 by mabenois          #+#    #+#             */
/*   Updated: 2025/11/26 15:14:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (NULL);
	if (size == 0)
		return (dst);
	i = 0;
	while (src[i] != 0 && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldest;
	size_t	lsrc;
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	ldest = ft_strlen(dst);
	if (size <= ldest)
		return (size + lsrc);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && j < (size - ldest) - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (ldest + lsrc);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	ls1;
	size_t	ls2;

	if (!s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ptr = ft_calloc(sizeof(char), (ls1 + ls2 + 1));
	if (!ptr)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(ptr, s1, ls1 + 1);
	ft_strlcat(ptr, s2, ls2 + ls1 + 1);
	if (s1)
		free(s1);
	return (ptr);
}

int	ft_contains_nl(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
