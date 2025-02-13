/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:31:11 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/10 13:29:28 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

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
			{	
				printf("duplicates\n");
				printf("player: %i\nexit: %i\ncoins: %i\ncoinsff: %i\n",data->item->player, data->item->exit, data->item->coins, data->item->coinsff);
				error_item_duplicate(data, data->map->gridff[y][x]);
			}
			x++;
		}
		y++;
	}
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
	{
		printf("player: %i\nexit: %i\ncoins: %i\ncoinsff: %i\n",data->item->player, data->item->exit, data->item->coins, data->item->coinsff);
		error_item_or_path(data);
	}
	find_duplicates(data);
	printf("player: %i\nexit: %i\ncoins: %i\ncoinsff: %i\n",data->item->player, data->item->exit, data->item->coins, data->item->coinsff);
	destroy_map(data->map->gridff, data->map->y);
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

int	valid_move(t_data *data, int off_x, int off_y)
{
	int	x;
	int	y;

	x = data->map->pos_x + off_x;
	y = data->map->pos_y + off_y;
	if (x > data->map->x || y > data->map->y || x < 0 || y < 0)
		return (0);
	if (data->map->grid[y][x] == FLOOR)
		return (1);
	else if (data->map->grid[y][x] == COLLECTIBLE)
		return (1);
	else if (data->map->grid[y][x] == OPEN_EXIT)
		return (1);
	else
		return (0);
}

void	move_player(t_data *data, int x, int y)
{
	
	if (valid_move(data, x, y))
	{
		data->map->grid[data->map->pos_y][data->map->pos_x] = FLOOR;
		if (data->map->grid[data->map->pos_y + y][data->map->pos_x + x] == COLLECTIBLE)
		{
			data->item->coins--;
			printf("coins left: %i\n", data->item->coins);
		}
		if (!data->item->coins)
			data->map->grid[data->map->ext_y][data->map->ext_x] = OPEN_EXIT;

		if (data->map->grid[data->map->pos_y + y][data->map->pos_x + x] == OPEN_EXIT)
		{
			printf("congratulations!\n--> YOU WIN!! <--\n");
			free_and_exit(data);
		}
		if (x >= 0)
			data->map->grid[data->map->pos_y += y][data->map->pos_x += x] = PLAYER;
		else
			data->map->grid[data->map->pos_y += y][data->map->pos_x += x] = PLAYER_LEFT;
		data->counter++;
		printf("mouvements: %i\n", data->counter);
		load_game(data);
	}
}

