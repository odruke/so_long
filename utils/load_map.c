/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:04:17 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/10 23:02:57 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	**copy_map(char **map, int max_y)
{
	int		y;
	char	**mapff;

	y = 0;
	mapff = (char **)malloc(sizeof(char *) * max_y + 1);
	if (!mapff)
	{
		perror("Error:\nallocation failed");
		exit(0);
	}
	while (y < max_y)
	{
		mapff[y] = ft_strdup(map[y]);
		y++;
	}
	mapff[y] = NULL;
	return (mapff);
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
	close(fd);
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
