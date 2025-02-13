/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:42 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/13 00:44:43 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_free_data(t_data *data)
{
	destroy_textures(data);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
//	if (data->mlx)
//		free(data->mlx);
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
	ft_free_data(data);
	exit (errno);
}

void	error_window(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nWindow generation failed\033[0m\n");
	ft_free_data(data);
	exit (errno);
}

void	error_malloc_failed(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nMemori allocation failed\033[0m\n");
	ft_free_data(data);
	exit (errno);
}
