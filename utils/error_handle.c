/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:42 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/10 13:42:49 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static void	free_data(t_data *data)
{
	destroy_textures(data);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	destroy_map(data->map->grid, data->map->y);
}

void	error_params(void)
{
	perror("\033[1;31m🛑Error🛑\nMust load a single map \033[0m\n");
	exit (errno);
}

void	error_mlx(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nmlx conection failed\033[0m\n");
	free_data(data);
	exit (errno);
}

void	error_window(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nWindow generation failed\033[0m\n");
	free_data(data);
	exit (errno);
}

void	error_texture_load(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nTexture load failed\033[0m\n");
	free_data(data);
	exit (errno);
}

void	error_map_load(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nMap load failed\033[0m\n");
	free_data(data);
	exit (errno);
}

void	error_no_collectibles(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nInvalid map: no collectibles found\033[0m\n");
	free_data(data);
	exit (errno);
}

void	error_item_or_path(t_data *data)
{
	if (data->item->player != 1)
	{
		perror("\033[1;31m🛑Error🛑\nInvalid map: must have 1 player\033[0m\n");
		free_data(data);
		exit (errno);
	}
	else if (data->item->exit != 1)
	{
		perror("\033[1;31m🛑Error🛑\nInvalid map: must have 1 accesible exit\033[0m\n");
		free_data(data);
		exit (errno);
	}
	else if (data->item->coins > data->item->coinsff)
	{
		perror("\033[1;31m🛑Error🛑\nInvalid map: not all coins accesible\033[0m\n");
		free_data(data);
		exit (errno);
	}
}

void	error_item_duplicate(t_data *data, char symbol)
{
	if (symbol == PLAYER)
	{
		perror("\033[1;31m🛑Error🛑\nInvalid map: multiple players not allowed\033[0m\n");
		free_data(data);
		exit (errno);
	}
	if (symbol == EXIT)
	{
		perror("\033[1;31m🛑Error🛑\nInvalid map: multiple exits not allowed\033[0m\n");
		free_data(data);
		exit (errno);
	}

}
