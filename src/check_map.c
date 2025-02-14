/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:44:01 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/14 21:57:51 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_ext(char *file_map)
{
	char	*check;
	int		len;

	len = ft_strlen(file_map);
	check = ft_strnstr(file_map, ".ber", ft_strlen(file_map));
	if (check == file_map + (len - 4))
		return (1);
	else
		return (0);
}

static int	is_rectangle(t_data *data)
{
	char				*valid_symbol;
	long unsigned int	len;
	int					y;
	int					x;

	valid_symbol = "10PCEo";
	y = 0;
	len = ft_strlen(data->map->grid[y]);
	while (data->map->grid[++y])
	{
		if (ft_strlen(data->map->grid[y]) != len)
			return (0);
		x = 0;
		while (data->map->grid[y][x])
			if (!strchr(valid_symbol, data->map->grid[y][x++]))
				return (0);
	}
	return (1);
}

static int	is_walled(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->grid[y][x])
		if (data->map->grid[y][x++] != WALL)
			return (0);
	x--;
	while (++y < data->map->y)
		if (data->map->grid[y][0] != WALL || data->map->grid[y][x] != WALL)
			return (0);
	y--;
	x = 0;
	while (data->map->grid[y][x])
		if (data->map->grid[y][x++] != WALL)
			return (0);
	return (1);
}

void	check_map(t_data *data, char *file_map)
{
	if (!valid_ext(file_map) || !is_rectangle(data) || !is_walled(data))
		error_map_format(data);
	find_coins(data);
	find_items_and_path(data);
}
