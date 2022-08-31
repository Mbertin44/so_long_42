/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:16:14 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/31 15:18:12 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_right(t_map *map)
{
	if (map->map[map->i][map->j + 1] == 'C')
		--map->c;
	if (map->map[map->i][map->j + 1] == 'E' && map->c == 0)
		win_game();
	map->map[map->i][map->j] = '0';
	map->map[map->i][map->j + 1] = 'P';
	map->move_index++;
	image_to_window(map);
	move_str(map);
}

void	move_left(t_map *map)
{
	if (map->map[map->i][map->j - 1] == 'C')
		--map->c;
	if (map->map[map->i][map->j - 1] == 'E' && map->c == 0)
		win_game();
	map->map[map->i][map->j] = '0';
	map->map[map->i][map->j - 1] = 'P';
	map->move_index++;
	image_to_window(map);
	move_str(map);
}

void	move_up(t_map *map)
{
	if (map->map[map->i - 1][map->j] == 'C')
		--map->c;
	if (map->map[map->i - 1][map->j] == 'E' && map->c == 0)
		win_game();
	map->map[map->i][map->j] = '0';
	map->map[map->i - 1][map->j] = 'P';
	map->move_index++;
	image_to_window(map);
	move_str(map);
}

void	move_down(t_map *map)
{
	if (map->map[map->i + 1][map->j] == 'C')
		--map->c;
	if (map->map[map->i + 1][map->j] == 'E' && map->c == 0)
		win_game();
	map->map[map->i][map->j] = '0';
	map->map[map->i + 1][map->j] = 'P';
	map->move_index++;
	image_to_window(map);
	move_str(map);
}
