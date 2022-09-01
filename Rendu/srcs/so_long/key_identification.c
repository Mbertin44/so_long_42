/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_identification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:55:30 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/01 09:34:24 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_identification(int key, t_map *map)
{
	if (key == 53)
	{
		printf("You press esc to exit the game ! Go back to work ...\n");
		exit (1);
		mlx_destroy_window(map->mlx, map->win);
	}
	if (key == 2)
	{
		map->i = 0;
		while (map->i < map->x - 1)
		{
			check_right(map);
			map->i++;
			map->j = 0;
		}
		check_right_villain(map);
	}
	key_identification_part_two(key, map);
	return (0);
}

int	key_identification_part_two(int key, t_map *map)
{
	if (key == 0)
	{
		map->i = 0;
		while (map->i < map->x - 1)
		{
			check_left(map);
			map->i++;
			map->j = 0;
		}
		check_left_villain(map);
	}
	if (key == 13)
	{
		map->i = 0;
		while (map->i < map->x - 1)
		{
			check_up(map);
			map->i++;
			map->j = 0;
		}
		check_up_villain(map);
	}
	key_identification_part_three(key, map);
	return (0);
}

int	key_identification_part_three(int key, t_map *map)
{
	if (key == 1)
	{
		map->i = 0;
		while (map->i < map->x - 1)
		{
			check_down(map);
			map->i++;
			map->j = 0;
		}
		check_down_villain(map);
	}
	return (0);
}
