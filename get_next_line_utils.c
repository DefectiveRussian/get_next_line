/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekhamid <dekhamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:53 by dekhamid          #+#    #+#             */
/*   Updated: 2025/04/28 22:02:03 by dekhamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_read_error(char *buffer, char *str, int bytes_read)
{
	free(buffer);
	if (bytes_read < 0 || !str)
		return (NULL);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	if (str == NULL)
		return (x);
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*str_join2(char *first, char *second)
{
	int		x;
	int		y;
	int		i;
	char	*dest;

	i = 0;
	x = ft_strlen(first);
	y = ft_strlen(second);
	dest = malloc(x + y + 1);
	if (dest == NULL)
		return (NULL);
	while (first && first[i] != 0)
	{
		dest[i] = first[i];
		i++;
	}
	i = 0;
	while (second && second[i] != 0)
	{
		dest[i + x] = second[i];
		i++;
	}
	free(first);
	dest[i + x] = '\0';
	return (dest);
}

int	str_chr(char *str)
{
	int	counter;

	counter = 0;
	while (str && str[counter] != '\0')
	{
		if (str[counter] == '\n')
			return (1);
		counter++;
	}
	return (0);
}
