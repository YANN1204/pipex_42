/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:28:51 by yrio              #+#    #+#             */
/*   Updated: 2024/01/29 13:50:29 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*readfile(int fd, char *stat)
{
	char	*buffer;
	int		isread;

	isread = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (ft_strchr(buffer, '\n') == NULL && isread != 0)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		buffer[isread] = '\0';
		if (isread == 0)
		{
			free(buffer);
			return (stat);
		}
		else if (isread == -1)
			return (NULL);
		stat = ft_strjoin2(stat, buffer);
	}
	free(buffer);
	return (stat);
}

char	*putline(char *stat, char *line)
{
	int		lenchar;

	if (stat == NULL || stat[0] == '\0')
		return (NULL);
	lenchar = 0;
	while (stat[lenchar] != '\n' && stat[lenchar] != '\0')
		lenchar++;
	if (stat[lenchar] == '\n')
		lenchar++;
	line = malloc((lenchar + 1) * sizeof(char));
	if (!line)
		return (NULL);
	lenchar = 0;
	while (stat[lenchar] != '\n' && stat[lenchar] != '\0')
	{
		line[lenchar] = stat[lenchar];
		lenchar++;
	}
	if (stat[lenchar] == '\n')
	{
		line[lenchar] = '\n';
		lenchar++;
	}
	line[lenchar] = '\0';
	return (line);
}

char	*putstat(char *stat)
{
	int		lenchar;
	int		i;
	char	*new_stat;

	if (stat == NULL)
		return (NULL);
	if (stat[0] == '\0' || ft_strchr(stat, '\n') == NULL)
	{
		free(stat);
		return (NULL);
	}
	lenchar = 0;
	while (stat[lenchar] != '\n' && stat[lenchar] != '\0')
		lenchar++;
	new_stat = malloc((ft_strlen(stat) - lenchar + 1) * sizeof(char));
	if (new_stat == NULL)
		return (NULL);
	i = 0;
	lenchar++;
	while (stat[lenchar] != '\0')
		new_stat[i++] = stat[lenchar++];
	new_stat[i] = '\0';
	free(stat);
	return (new_stat);
}

char	*get_next_line(int fd, char *delimiteur)
{
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	stat = readfile(fd, stat);
	line = putline(stat, line);
	stat = putstat(stat);
	if (ft_strlen(line) == ft_strlen(delimiteur) + 1 && \
		!ft_strncmp(line, delimiteur, ft_strlen(delimiteur)))
		free(stat);
	return (line);
}

/*
int	main(void)
{
	char		*namefile;
	char		*line;
	char		*line2;
	//char		*line3;
	int			fd;

	namefile = "numbers.dict";
	fd = open(namefile, O_RDONLY);
	if (fd == -1)
	{
		perror("Le fichier n'a pas pu etre ouvert");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd);
	printf("%s", line2);
	//line3 = get_next_line(fd);
	//printf("%s", line3);
	if (line != NULL)
	{
		free(line);
		//printf("bien malloc line\n");
	}
	if (line2 != NULL)
	{
		//free(line2);
		//printf("bien malloc line2\n");
	}
	if (line3 != NULL)
	{
		free(line3);
		printf("bien malloc line3\n");
	}
	return (0);
}
*/
