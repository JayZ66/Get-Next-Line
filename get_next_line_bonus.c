/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:28:36 by jeguerin          #+#    #+#             */
/*   Updated: 2023/11/07 15:16:08 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_stash(char *stash)
{
	int		i;
	char	*next_line;
	int		len;

	next_line = 0;
	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		i++;
		len = ft_strlen(stash + i);
		next_line = ft_strndup(stash + i, len);
	}
	else
		next_line = ft_strndup(stash + i, ft_strlen(stash + i));
	free(stash);
	return (next_line);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	if (ft_strchr(stash, '\n') == 1)
	{
		while (stash[i] != '\n' && stash[i])
			i++;
		if (stash[i] == '\n')
			i++;
	}
	else
		i = ft_strlen(stash);
	line = ft_strndup(stash, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	int			rd;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	rd = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		stash[fd] = ft_join(stash[fd], buffer);
		if (ft_strchr(stash[fd], '\n') == 1)
			break ;
	}
	free(buffer);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd1;
// 	int	fd2;
// 	char *line;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("empty2.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	while (line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd1);
// 	}
// 	return 0;
// }

// maj stash
// extraire et mettre a jour la stash strndup(stash + i, len de stash + i)
