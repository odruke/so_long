/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:04:17 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/21 15:11:58 by odruke-s       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**copy_map(t_data *data, char **map, int max_y)
{
	int		y;
	char	**mapff;

	y = 0;
	mapff = (char **)malloc(sizeof(char *) * max_y);
	if (!mapff)
		error_malloc_failed(data);
	while (y < max_y)
	{
		mapff[y] = ft_strdup(map[y]);
		y++;
	}
	return (mapff);
}

void	free_single_line(char *temp, int fd)
{
	char	*free_me;

	free_me = get_next_line(fd);
	free(temp);
	while (free_me)
	{
		free(free_me);
		free_me = get_next_line(fd);
	}
}

char	**load_map(t_data *data, char *map_file)
{
	char	*line;
	char	*temp;
	char	**map;
	int		fd;

	temp = "";
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_map_load(data);
	line = ft_strdup("");
	while (temp)
	{
		temp = get_next_line(fd);
		if (!temp || temp[0] == '\n')
			break ;
		line = ft_strjoin(line, temp);
		data->map->y++;
		free(temp);
	}
	map = ft_split(line, '\n');
	if (temp)
		free_single_line(temp, fd);
	close(fd);
	free(line);
	return (map);
}
