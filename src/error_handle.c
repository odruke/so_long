/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:42 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/14 21:41:59 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_params(void)
{
	perror("\033[1;31m🛑Error🛑\nMust load a single map \033[0m\n");
}

void	error_mlx(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nmlx conection failed\033[0m\n");
	free_and_exit(data);
}

void	error_window(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nWindow generation failed\033[0m\n");
	free_and_exit(data);
}

void	error_malloc_failed(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nMemory allocation failed\033[0m\n");
	free_and_exit(data);
}

void	error_map_format(t_data *data)
{
	perror("\033[1;31m🛑Error🛑\nIvalid map format\033[0m\n");
	free_and_exit(data);
}
