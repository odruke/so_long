/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:41:14 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/14 00:50:16 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	destroy_map(char **map, int max_y)
{
	int	y;

	y = 0;
	while (y < max_y)
	{
		free(map[y]);
		map[y++] = NULL;
	}
	free(map);
	map = NULL;
}

void	destroy_textures(t_data *data)
{
	if (data->texture)
	{
		if (data->texture->floor)
			mlx_destroy_image(data->mlx, data->texture->floor);
		if (data->texture->wall)
			mlx_destroy_image(data->mlx, data->texture->wall);
		if (data->texture->player)
			mlx_destroy_image(data->mlx, data->texture->player);
		if (data->texture->collectible)
			mlx_destroy_image(data->mlx, data->texture->collectible);
		if (data->texture->closed_exit)
			mlx_destroy_image(data->mlx, data->texture->closed_exit);
		if (data->texture->open_exit)
			mlx_destroy_image(data->mlx, data->texture->open_exit);
		if (data->texture->player_left)
			mlx_destroy_image(data->mlx, data->texture->player_left);
		free(data->texture);
	}
}

int	free_and_exit(t_data *data)
{
	if (data)
	{
		destroy_textures(data);
		if (data->item)
			free(data->item);
		if (data->map)
		{
			if (data->map->grid)
				destroy_map(data->map->grid, data->map->y);
			if (data->map->gridff)
				destroy_map(data->map->gridff, data->map->y);
			free(data->map);
		}
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free(data);
	}
	ft_printf("\033[1;35m✨Memory freed successfully🚀\n🚪Exiting game👋\033[0m\n");
	exit(errno);
	return (0);
}
