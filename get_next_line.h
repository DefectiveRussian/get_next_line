/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekhamid <dekhamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:55 by dekhamid          #+#    #+#             */
/*   Updated: 2025/04/28 16:09:58 by dekhamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
int		str_chr(char *str);
char	*str_join2(char *first, char *second);
size_t	ft_strlen(const char *str);
char	*separator(char *str);
char	*reverse_separator(char *str);
char	*read_and_split(int fd);
char	*handle_read_error(char *buffer, char *str, int bytes_read);

#endif