/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_villain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:07:25 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/01 09:34:20 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
