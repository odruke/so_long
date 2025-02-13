/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:42:25 by odruke-s          #+#    #+#             */
/*   Updated: 2025/02/07 23:37:50 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h> 
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define TILE_SIZE 50
# define PLAYER 'P'
# define PLAYER_LEFT 'L'
# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define OPEN_EXIT 'o'
# define COLLECTIBLE 'C'
# define ESC_KEY 65307
# define UP_KEY_W 119
# define DOWN_KEY_S 115
# define LEFT_KEY_A 97
# define RIGHT_KEY_D 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

typedef struct s_texture
{
	void		*player;
	void		*player_left;
	void		*floor;
	void		*wall;
	void		*open_exit;
	void		*closed_exit;
	void		*collectible;
} t_texture;

typedef struct s_item
{
	int			player;
	int			exit;
	int			coins;
	int			coinsff;
} t_item;

typedef struct s_map
{
	char		**grid;
	char		**gridff;
	int			y;
	int			x;
	int			pos_y;
	int			pos_x;
	int			ext_y;
	int			ext_x;
} t_map;

typedef struct	s_data
{
	void 		*mlx;
	void 		*window;
	t_texture	*texture;
	t_map		*map;
	t_item		*item;
	int			counter;
} t_data;

char	**load_map(t_data *data, char *map_file);
char	**copy_map(t_data *data, char **map, int max_y);
void	draw_map(t_data *data);
void	draw_frame(t_data *data);
void	load_textures(t_data *data);
void	destroy_map(char **map, int max_y);
void	destroy_textures(t_data *data);
void	ft_free_data(t_data *data);
int		free_and_exit(t_data *data);
int		get_height(char **map);
int		find_coins(t_data *data);
void	find_items_and_path(t_data *data);
void	find_exit(t_data *data);
void	check_map(t_data *data, char *file_map);
void	move_player(t_data *data, int x, int y);
void	load_game(t_data *data);
void    error_params(void);
void	error_mlx(t_data *data);
void    error_window(t_data *data);
void    error_texture_load(t_data *data);
void	error_map_load(t_data *data);
void	error_no_collectibles(t_data *data);
void	error_item_or_path(t_data *data);
void	error_item_duplicate(t_data *data, char symbol);
void	error_malloc_failed(t_data *data);
void	valid_path(t_data *data, int y, int x);

#endif
