/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:42 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/14 21:39:16 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_texture_load(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nTexture load failed\033[0m\n");
	free_and_exit(data);
}

void	error_map_load(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nMap load failed\033[0m\n");
	free_and_exit(data);
}

void	error_no_collectibles(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nInvalid map: no collectibles found\033[0m\n");
	free_and_exit(data);
}

void	error_item_or_path(t_data *data)
{
	if (data->item->player != 1)
	{
		perror("\033[1;31m🛑Error🛑\nInvalid map: must have 1 player\033[0m\n");
		free_and_exit(data);
	}
	else if (data->item->exit != 1)
	{
		perror("\033[1;31m🛑Error🛑\nMap: must have 1 accesible exit\033[0m\n");
		free_and_exit(data);
	}
	else if (data->item->coins > data->item->coinsff)
	{
		perror("\033[1;31m🛑Error🛑\nMap: not all coins accesible\033[0m\n");
		free_and_exit(data);
	}
}

void	error_item_duplicate(t_data *data, char symbol)
{
	if (symbol == PLAYER)
	{
		perror("\033[1;31m🛑Error🛑\nMap: multiple players not allowed\033[0m\n");
		free_and_exit(data);
	}
	if (symbol == EXIT)
	{
		perror("\033[1;31m🛑Error🛑\nMap: ultiple exits not allowed\033[0m\n");
		free_and_exit(data);
	}
}
