/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:00:56 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/31 15:08:15 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	xpm_to_image(t_map *map)
{
		map->wooden = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/wooden.xpm", &map->img_width,
			&map->img_height);
		map->close_door = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/close_door.xpm", &map->img_width,
			&map->img_height);
		map->open_door = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/open_door.xpm", &map->img_width,
			&map->img_height);
		map->close_door = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/close_door.xpm", &map->img_width,
			&map->img_height);
		map->slime = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/slime.xpm", &map->img_width,
			&map->img_height);
		map->wall = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/wall.xpm", &map->img_width,
			&map->img_height);
		map->coin = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/bag_coin.xpm", &map->img_width,
			&map->img_height);
		map->villain = mlx_xpm_file_to_image(map->mlx,
			"../Image/xpm/villain.xpm", &map->img_width,
			&map->img_height);
}

void	image_to_window(t_map *map)
{
	map->i = 0;
	map->pos_y = 0;
	while (map->i < map->x)
	{
		map->pos_x = 0;
		map->j = 0;
		while (map->j < ft_strlen(map->map[0]) - 1)
		{
			if (map->map[map->i][map->j] == '1')
			{
				mlx_put_image_to_window(map->mlx, map->win,
					map->wall, map->pos_x, map->pos_y);
				map->pos_x += 64;
			}
			if (map->map[map->i][map->j] == 'P')
			{
				mlx_put_image_to_window(map->mlx, map->win,
					map->slime, map->pos_x, map->pos_y);
				map->pos_x += 64;
			}
			else
				image_to_window_part_two(map);
			map->j++;
		}
		map->i++;
		map->pos_y += 64;
	}
}

void	image_to_window_part_two(t_map *map)
{
	if (map->map[map->i][map->j] == '0')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->wooden, map->pos_x, map->pos_y);
		map->pos_x += 64;
	}
	if (map->map[map->i][map->j] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->coin, map->pos_x, map->pos_y);
		map->pos_x += 64;
	}
	if (map->map[map->i][map->j] == 'E' && map->c != 0)
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->close_door, map->pos_x, map->pos_y);
		map->pos_x += 64;
	}
	if (map->map[map->i][map->j] == 'E' && map->c == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->open_door, map->pos_x, map->pos_y);
		map->pos_x += 64;
	}
	if (map->map[map->i][map->j] == 'X')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->villain, map->pos_x, map->pos_y);
		map->pos_x += 64;
	}
}
