/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekhamid <dekhamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:46 by dekhamid          #+#    #+#             */
/*   Updated: 2025/04/28 22:01:35 by dekhamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*separator(char *str)
{
	char	*kek;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	kek = malloc(i + 1);
	if (kek == NULL)
		return (NULL);
	while (j < i)
	{
		kek[j] = str[j];
		j++;
	}
	kek[j] = '\0';
	return (kek);
}

char	*reverse_separator(char *str)
{
	char	*kek;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	len = len - i;
	kek = malloc(len + 1);
	if (kek == NULL)
		return (NULL);
	while (j < len)
	{
		kek[j] = str[i + j];
		j++;
	}
	kek[j] = '\0';
	return (kek);
}

char	*read_and_split(int fd)
{
	int			bytes_read;
	char		*buffer;
	static char	*str = NULL;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		if (str_chr(str) == 1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = str_join2(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*result;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_and_split(fd);
	result = separator(str);
	str = reverse_separator(str);
	free(str);
	return (result);
}

int	main(void)
{
	int		fd;
	char	*str = NULL;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	return (0);
}
