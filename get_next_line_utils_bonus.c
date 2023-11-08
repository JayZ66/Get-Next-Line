/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:29:25 by jeguerin          #+#    #+#             */
/*   Updated: 2023/11/08 09:49:47 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if (str[i] == '\0')
		return (0);
	return (-1);
}

char	*ft_strndup(const char *str, int size)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str || size == 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;
	size_t	lens;

	i = 0;
	j = 0;
	lens = ft_strlen(s2);
	if (!s1)
		return (ft_strndup(s2, lens));
	lens = lens + ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (lens + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
