/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebronzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:55:22 by ebronzin          #+#    #+#             */
/*   Updated: 2023/02/08 13:40:28 by ebronzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_aus(int fd, char *line)
{
	int		bytlet;
	char	*t;

	t = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!t)
		return (NULL);
	bytlet = 1;
	while (!(ft_strchr(line, '\n')) && bytlet > 0)
	{
		bytlet = read(fd, t, BUFFER_SIZE);
		if (bytlet == -1)
		{
			free(t);
			return (NULL);
		}
		t[bytlet] = '\0';
		line = ft_strjoin(line, t);
	}
	free(t);
	return (line);
}

char	*ft_linlett(char *iniz)
{
	int		i;
	char	*line;

	i = 0;
	if (!iniz[i])
		return (NULL);
	while (iniz[i] && iniz[i] != '\n')
		i++;
	line = (char *)malloc(2 + i);
	if (!line)
		return (NULL);
	i = 0;
	while (iniz[i] && iniz[i] != '\n')
	{
		line[i] = iniz[i];
		i++;
	}
	if (iniz[i] == '\n')
	{
		line[i] = iniz[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_mviniz(char *iniz)
{
	char	*newbuff;
	int		i;
	int		j;

	i = 0;
	while (iniz[i] && iniz[i] != '\n')
		i++;
	if (!iniz[i])
	{
		free(iniz);
		return (NULL);
	}
	newbuff = (char *)malloc(sizeof(char) * (ft_strlen(iniz) - i + 1));
	if (!newbuff)
		return (NULL);
	i++;
	j = 0;
	while (iniz[i])
		newbuff[j++] = iniz[i++];
	newbuff[j] = '\0';
	free(iniz);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	char		*t;
	static char	*tank;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tank = ft_aus(fd, tank);
	if (!tank)
		return (NULL);
	t = ft_linlett(tank);
	tank = ft_mviniz(tank);
	return (t);
}
