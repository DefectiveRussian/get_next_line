/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekhamid <dekhamid@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:46 by dekhamid          #+#    #+#             */
/*   Updated: 2024/12/12 13:48:58 by dekhamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*separator(char* str)
{
	char*	kek;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	kek = malloc(i + 1);
	while(j < i)
	{
		kek[j] = str[j];
		j++;
	}
	kek[j] = '\0';
	return (kek);
}

char	*reverse_separator(char* str)
{
	char*	kek;
	int		i;
	int		j;
	int		len;

	len = str_len(str);
	i = 0;
	j = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	len = len - i;
	kek = malloc(len + 2);
	while(j < len)
	{
		kek[j] = str[i + j];
		j++; 
	}
	kek[j] = '\0';
	free(str);
	return(kek);
}

char *read_and_split(int fd)
{
	int		bytes_read;
	char	*buffer;
	static char* 	str = NULL;

	buffer = malloc(11);
	bytes_read = 1;
	while(bytes_read != 0)
	{
		if(str_chr(str) == 1)
			break;
		bytes_read = read(fd, buffer, 10);
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
	char 	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_and_split(fd);
	result = separator(str);
	str = reverse_separator(str);
	return (result);
}

/*int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	char *str = NULL;

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
}*/