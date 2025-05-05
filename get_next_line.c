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
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*reverse_separator(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	j = 0;
	while (str[i + j] != '\0')
		j++;
	result = malloc(j + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (str[i + j] != '\0')
	{
		result[j] = str[i + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*read_and_split(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*str;

	str = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (handle_read_error(buffer, str, bytes_read));
		buffer[bytes_read] = '\0';
		str = str_join2(str, buffer);
		if (!str || str_chr(str) == 1)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*str;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = read_and_split(fd);
		if (!str)
			return (NULL);
	}
	result = separator(str);
	if (!result)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	temp = str;
	str = reverse_separator(str);
	free(temp);
	return (result);
}

/*int main(void)
{
	int fd;
	char *str;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}

	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	printf("\n");
	close(fd);
	return (0);
}
*/