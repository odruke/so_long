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
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		error_malloc_failed(data);
	data->map->y = 0;
	data->map->x = 0;
	data->map->pos_y = 0;
	data->map->pos_x = 0;
	data->map->ext_y = 0;
	data->map->ext_x = 0;data->texture->collectible = NULL;
}

void	init_data(t_data *data, char *file_map)
{
	data->counter = 0;
	data->mlx= NULL;
	data->window = NULL;
	init_structs(data);
	data->map->grid = load_map(data, file_map);
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
	find_coins(data);
	find_items_and_path(data);
}

int	main(int ac, char **av)
{
	errno = 0;
	if (ac != 2)
		error_params();
	else
	{
		t_data *data;

		data = ft_calloc(1, sizeof(t_data));
		init_data(data, av[1]);
		printf("data initialized\n");
		printf("preparing mlx_init\n");
		data->mlx = mlx_init();
		if (!data->mlx)
			error_mlx(data);
		printf("mlx initiated\n");
		printf("preparing new window\n");
		data->window = mlx_new_window(data->mlx, data->map->x * TILE_SIZE, data->map->y * TILE_SIZE, "patata");
		if(!data->window)
			error_window(data);
		printf("new window initiated\n");
		printf("loading textures\n");
		load_textures(data);
		printf("textures loaded\n");
		printf("loading game\n");
		load_game(data);
		printf("game loaded\n");
		mlx_hook(data->window, 2, (1L << 0), handle_keypress, data);
		mlx_hook(data->window, 17, 0, free_and_exit, data);
		mlx_loop(data->mlx);
	}
}
