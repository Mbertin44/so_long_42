/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momo <momo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:15:23 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/11 11:14:17 by momo             ###   ########.fr       */
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

int	main(int argc, char const *argv[])
{
	t_map	map;

	map.move_index = 0;
	check_arg(&argc, argv[1]);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0)
		exit (0);
	printf("coucou");
	check_all_map(&map, argv);
	ft_mlx_put(&map);
	return (0);
}

/*

	Pour checker les leaks : leaks --atExit -- ./so_long ../maps/map2.ber

*/