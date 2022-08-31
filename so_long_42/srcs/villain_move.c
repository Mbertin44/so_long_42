/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:18:40 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/31 16:01:15 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_right_villain(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
			if (map->map[map->i][map->j] == 'X'
				&& map->map[map->i][map->j + 1] == '0')
			{
				move_right_villain(map);
				break ;
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	check_left_villain(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
			if (map->map[map->i][map->j] == 'X'
				&& map->map[map->i][map->j - 1] == '0')
			{
				move_left_villain(map);
				break ;
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	check_up_villain(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
			if (map->map[map->i][map->j] == 'X'
				&& map->map[map->i - 1][map->j] == '0')
			{
				move_up_villain(map);
				break ;
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	check_down_villain(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
			if (map->map[map->i][map->j] == 'X'
				&& map->map[map->i + 1][map->j] == '0')
			{
				move_down_villain(map);
				break ;
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	move_right_villain(t_map *map)
{
	map->map[map->i][map->j] = '0';
	map->map[map->i][map->j + 1] = 'X';
	image_to_window(map);
	move_str(map);
}
void	move_left_villain(t_map *map)
{
	map->map[map->i][map->j] = '0';
	map->map[map->i][map->j - 1] = 'X';
	image_to_window(map);
	move_str(map);
}
void	move_up_villain(t_map *map)
{
	map->map[map->i][map->j] = '0';
	map->map[map->i -1][map->j] = 'X';
	image_to_window(map);
	move_str(map);
}
void	move_down_villain(t_map *map)
{
	map->map[map->i][map->j] = '0';
	map->map[map->i + 1][map->j] = 'X';
	image_to_window(map);
	move_str(map);
}
