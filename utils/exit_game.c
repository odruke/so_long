/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:41:14 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/12 17:26:24 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	destroy_map(char **map, int max_y)
{
	int	y;

	y = 0;
	while (y < max_y)
		free(map[y++]);
	free(map);
}

void	destroy_textures(t_data *data)
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

int	free_and_exit(t_data *data)
{
	destroy_textures(data);
	printf("textures destroyed\n");
	mlx_destroy_window(data->mlx, data->window);
	printf("window destroyed\n");
	mlx_destroy_display(data->mlx);
	printf("mlx conexion destroyed destroyed\n");
	free(data->mlx);
	printf("mlx freed\n");
	destroy_map(data->map->grid, data->map->y);
	printf("map destroyed\n");
	free(data->item);
	free(data->map);
	free(data);
	exit(0);
	return (0);
}
