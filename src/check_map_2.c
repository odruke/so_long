/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:38:49 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/13 10:39:26 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	find_duplicates(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map->y)
	{
		x = 0;
		while (x < data->map->x)
		{
			if (data->map->gridff[y][x] == PLAYER || data->map->gridff[y][x] == EXIT)
				error_item_duplicate(data, data->map->gridff[y][x]);
			x++;
		}
		y++;
	}
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

void	find_items_and_path(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map->y)
	{
		x = 0;
		while (x < data->map->x)
		{

			if (data->map->gridff[y][x] == PLAYER)
				valid_path(data, y, x);
			x++;
		}
		y++;
	}
    	if (data->item->player != 1 || data->item->exit != 1 || data->item->coins != data->item->coinsff)
			error_item_or_path(data);
	find_duplicates(data);
}


int	find_coins(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map->y)
	{
		x = 0;
		while (x < data->map->x)
		{
			if (data->map->grid[y][x] == COLLECTIBLE)
				data->item->coins++;
			x++;
		}
		y++;
	}
	if (!data->item->coins)
		error_no_collectibles(data);
	return (data->item->coins);
}
