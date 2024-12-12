/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekhamid <dekhamid@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:53 by dekhamid          #+#    #+#             */
/*   Updated: 2024/12/12 14:34:27 by dekhamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		one;
	int		two;
	char	*dest;

	one = ft_strlen(s1);
	two = ft_strlen(s2);
	dest = malloc(sizeof(char) * (one + two + 1));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1, one + 1);
	ft_strlcat(dest, s2, one + two + 1);
	return (dest);
}

void	*ft_calloc(size_t num, size_t dim)
{
	void		*ptr;
	char		*d;
	size_t		x;

	ptr = malloc(num * dim);
	if (ptr == 0)
		return (0);
	d = (char *)ptr;
	x = 0;
	while (x < dim * num)
	{
		d[x] = '\0';
		x++;
	}
	return (ptr);
}
