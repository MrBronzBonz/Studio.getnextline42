/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebronzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:37:25 by ebronzin          #+#    #+#             */
/*   Updated: 2023/02/08 12:48:26 by ebronzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_linlett(char *src);
char	*ft_strchr(char *s, int c);
char	*ft_mviniz(char *start);
char	*ft_strjoin(char *start, char *buff);
char	*ft_aus(int fd, char *line);

#endif
