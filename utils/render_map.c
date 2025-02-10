/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:25:00 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/08 22:32:17 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_textures(t_data *data)
{
	data->texture->wall = mlx_xpm_file_to_image(data->mlx, "./imgs/muro_1.xpm", &(int){0}, &(int){0});
	if (!data->texture->wall)
		error_texture_load(data);
	data->texture->floor = mlx_xpm_file_to_image(data->mlx, "./imgs/hierba_1.xpm", &(int){0}, &(int){0});
	if (!data->texture->floor)
		error_texture_load(data);
	data->texture->player = mlx_xpm_file_to_image(data->mlx, "./imgs/player_sweep_1_grass.xpm", &(int){0}, &(int){0});
	if (!data->texture->player)
		error_texture_load(data);
	data->texture->collectible = mlx_xpm_file_to_image(data->mlx, "./imgs/moneda_2_grass.xpm", &(int){0}, &(int){0});
	if (!data->texture->collectible)
		error_texture_load(data);
	data->texture->closed_exit = mlx_xpm_file_to_image(data->mlx, "./imgs/pc_1_grass.xpm", &(int){0}, &(int){0});
	if (!data->texture->closed_exit)
		error_texture_load(data);
	data->texture->open_exit = mlx_xpm_file_to_image(data->mlx, "./imgs/pc_1_on_grass.xpm", &(int){0}, &(int){0});
	if (!data->texture->open_exit)
		error_texture_load(data);
}

void	*ide_textures(t_texture *texture, char ide)
{
	if (ide == PLAYER)
		return (texture->player);
	else if (ide == COLLECTIBLE)
		return (texture->collectible);
	else if (ide == EXIT)
		return (texture->closed_exit);
	else if (ide == OPEN_EXIT)
		return (texture->open_exit);
	else if (ide == WALL)
		return (texture->wall);
	else if (ide == FLOOR)
		return (texture->floor);
	return (NULL);
}

void	draw_map(t_data *data)
{
	static	int	check;
	int		y;
	int		x;

	y = 0;
	while (y < data->map->y)
	{
		x = 0;
		while (x < data->map->x)
		{
			mlx_put_image_to_window(data->mlx, data->window, data->texture->floor, x * TILE_SIZE, y * TILE_SIZE);
			if (data->map->grid[y][x] == WALL)
				mlx_put_image_to_window(data->mlx, data->window, data->texture->wall, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	if (!check)
	{
		printf("map loaded\n");
		check = 1;
	}
}

void	draw_frame(t_data *data)
{
	static	int	check;
	int		y;
	int		x;
	void	*img;

	y = 0;
	while (y < data->map->y)
	{
		x = 0;
		while (x < data->map->x)
		{
			img = ide_textures(data->texture, data->map->grid[y][x]);
			if (img)
				mlx_put_image_to_window(data->mlx, data->window, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	if (!check)
	{
		printf("items loaded\n");
		check = 1;
	}
}
