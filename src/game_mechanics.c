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
#include "so_long.h"

int	handle_keypress(int	keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		free_and_exit(data);
    else if (keycode == UP_KEY_W || keycode == UP_ARROW)
		move_player(data, 0, -1);
    else if (keycode == DOWN_KEY_S || keycode == DOWN_ARROW)
		move_player(data, 0, 1);
    else if (keycode == LEFT_KEY_A || keycode == LEFT_ARROW)
		move_player(data, -1, 0);
    else if (keycode == RIGHT_KEY_D || keycode == RIGHT_ARROW)
		move_player(data, 1, 0);
	return (0);
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
			ft_printf("\033[1;33m🪙 coins left: %d 🪙\033[0m\n", data->item->coins);
		}
		if (!data->item->coins)
			data->map->grid[data->map->ext_y][data->map->ext_x] = OPEN_EXIT;

		if (data->map->grid[data->map->pos_y + y][data->map->pos_x + x] == OPEN_EXIT)
		{
			ft_printf("\033[1;33m🏆 ¡YOU WIN! 🏆\033[0m\n");
			free_and_exit(data);
		}
		if (x >= 0)
			data->map->grid[data->map->pos_y += y][data->map->pos_x += x] = PLAYER;
		else
			data->map->grid[data->map->pos_y += y][data->map->pos_x += x] = PLAYER_LEFT;
		data->counter++;
		ft_printf("\033[1;34m🔵 mouvements: %d\033[0m\n", data->counter);
		load_game(data);
	}
}

