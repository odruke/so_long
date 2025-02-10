/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:44:01 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/10 14:42:43 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	valid_ext(char *file_map)
{
	char	*check;
	int		len;
	
	len = ft_strlen(file_map);
	check = ft_strnstr(file_map, ".ber", ft_strlen(file_map));
	if(check == file_map + (len - 4))
		return (1);
	else
		return (0);
}

static int	is_rectangle(t_data *data)
{
	char	*valid_symbol; 
	long unsigned int	len;
	int		y;
	int		x;

	valid_symbol = "10PCEo";
	y = 0;
	len = ft_strlen(data->map->grid[y]);
	while (data->map->grid[++y])
	{
		if (ft_strlen(data->map->grid[y]) != len)
		{
			printf("not rectangle bad lenght\n");
			return (0);
		}
		x = 0;
		while (data->map->grid[y][x])
			if (!strchr(valid_symbol, data->map->grid[y][x++]))
			{
				printf("not rectangle bad symbol\n");
				return (0);
			}
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

void	find_items(t_data *data, int y, int x)
{
	if (data->map->grid[y][x] == PLAYER)
	{
		data->item->player++;
		data->map->pos_y = y;
		data->map->pos_x = x;
	}
	else if (data->map->grid[y][x] == COLLECTIBLE)
		data->item->coinsff++;
	else if (data->map->grid[y][x] == EXIT)
	{
		data->item->exit++;
		data->map->ext_y = y;
		data->map->ext_x = x;
	}
}

void	valid_path(t_data *data, int y, int x)
{
	char	*valid_symbol; 
	
	valid_symbol = "0PCE";
	find_items(data, y, x);
	data->map->gridff[y][x] = 'x';
	if ((y + 1) < data->map->y && ft_strchr(valid_symbol, data->map->gridff[y + 1][x]))
		valid_path(data, y + 1, x);
	if ((y - 1) >= 0 && ft_strchr(valid_symbol, data->map->gridff[y - 1][x]))
		valid_path(data, y - 1, x);
	if ((x + 1) < data->map->x && ft_strchr(valid_symbol, data->map->gridff[y][x + 1]))
		valid_path(data, y, x + 1);
	if ((x - 1) >= 0 && ft_strchr(valid_symbol, data->map->gridff[y][x - 1]))
		valid_path(data, y, x - 1);

}

void	check_map(t_data *data, char *file_map)
{
	if (!valid_ext(file_map) || !is_rectangle(data))
	{
		printf("no rectanglei\n");
		free_and_exit(data);
	}
	if (!is_walled(data))
	{
		printf("bad wall\n");
		free_and_exit(data);
	}
}
