/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebronzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:55:54 by ebronzin          #+#    #+#             */
/*   Updated: 2023/02/08 11:12:01 by ebronzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c == '\0')
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *start, char *buff)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!start)
	{
		start = (char *)malloc(1 * sizeof(char));
		start[0] = '\0';
	}
	if (!start || !buff)
		return (NULL);
	ptr = malloc((1 + ft_strlen(start) + ft_strlen(buff)) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	j = 0;
	if (start)
		while (start[++i] != '\0')
			ptr[i] = start[i];
	while (buff[j] != '\0')
		ptr[i++] = buff[j++];
	ptr[ft_strlen(start) + ft_strlen(buff)] = '\0';
	free(start);
	return (ptr);
}
