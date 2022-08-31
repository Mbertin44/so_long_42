/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:15:23 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/31 11:11:11 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_arg(int *argc, char const *argv)
{
	int	ext;

	if (*argc != 2)
	{
		printf("Error\nWrong number of arguments at runtime\n");
		exit (1);
	}
	ext = ft_strlen(argv) - 4;
	if (ft_strncmp(".ber", &argv[ext], 4) != 0)
	{
		printf("Error\nThe arguments at runtime is not a .ber\n");
		exit (1);
	}
}

void	check_all_map(t_map *map, char const *argv[])
{
	size_map_vertical(map);
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
		exit (0);
	print_map(map);
	close(map->fd);
	check_rectangle(map);
	check_wall_horizontal(map);
	check_wall_vertical(map);
	check_unknow_set(map);
	count_set(map);
	check_error_number_set(map);
}

void	ft_mlx_put(t_map *map)
{
	map->i = -1;
	map->j = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	map->mlx = mlx_init();
	xpm_to_image(map);
	map->win = mlx_new_window(map->mlx, ((ft_strlen(map->map[0]) - 1) * 64),
			map->x * 64, "so_long");
	image_to_window(map);
	mlx_hook(map->win, 2, 1L << 0, key_identification, map);
	mlx_hook(map->win, 17, 0, esc_game, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char const *argv[])
{
	t_map	map;

	check_arg(&argc, argv[1]);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0)
		exit (0);
	check_all_map(&map, argv);
	ft_mlx_put(&map);
	return (0);
}

/*
	Je dois faire des malloc pour chaque ligne de mon tableau !!!
	Je dois malloc ma struct !!!

	- Faire une condition pour que la slim ne puisse pas aller sur la porte si c != 0

	OUBLIE PAS !!!! :
	-	Change ton makefile pour faire fonctionner la mlx !!!
*/