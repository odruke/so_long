/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:52:31 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/21 15:10:02 by odruke-s       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_structs(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_texture));
	if (!data->texture)
		error_malloc_failed(data);
	data->texture->player = NULL;
	data->texture->player_left = NULL;
	data->texture->floor = NULL;
	data->texture->wall = NULL;
	data->texture->open_exit = NULL;
	data->texture->closed_exit = NULL;
	data->texture->collectible = NULL;
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		error_malloc_failed(data);
	data->map->y = 0;
	data->map->x = 0;
	data->map->pos_y = 0;
	data->map->pos_x = 0;
	data->map->ext_y = 0;
	data->map->ext_x = 0;
}

void	init_data(t_data *data, char *file_map)
{
	data->counter = 0;
	data->mlx = NULL;
	data->window = NULL;
	init_structs(data);
	data->map->grid = load_map(data, file_map);
	if (!data->map->grid[0])
		error_map_format(data);
	data->map->x = ft_strlen(data->map->grid[0]);
	data->map->gridff = copy_map(data, data->map->grid, data->map->y);
	data->item = ft_calloc(1, sizeof(t_item));
	if (!data->item)
		error_malloc_failed(data);
	data->item->player = 0;
	data->item->exit = 0;
	data->item->coins = 0;
	data->item->coinsff = 0;
	check_map(data, file_map);
	ft_printf("\033[1;32m✅ map check :OK\033[0m\n");
}

static void	start_game(t_data *data)
{
	load_textures(data);
	ft_printf("\033[1;32m✅ textures loaded\033[0m\n");
	load_game(data);
	ft_printf("\033[1;32m✅ game loaded!\033[0m\n");
}

int	main(int ac, char **av)
{
	t_data	*data;

	errno = 0;
	if (ac != 2)
		error_params();
	else
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
			error_malloc_failed(data);
		init_data(data, av[1]);
		data->mlx = mlx_init();
		if (!data->mlx)
			error_mlx(data);
		ft_printf("\033[1;32m✅ Mlx connection establised \033[0m\n");
		data->window = mlx_new_window(data->mlx,
				data->map->x * TILE_SIZE, data->map->y * TILE_SIZE, "so_long");
		if (!data->window)
			error_window(data);
		ft_printf("\033[1;32m✅ window created \033[0m\n");
		start_game(data);
		mlx_hook(data->window, 2, (1L << 0), handle_keypress, data);
		mlx_hook(data->window, 17, 0, free_and_exit, data);
		mlx_loop(data->mlx);
	}
}
