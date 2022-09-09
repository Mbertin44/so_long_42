/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:41:10 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/06 08:42:34 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_right(t_map *map)
{
	while (map->j < (ft_strlen(map->map[0]) - 1))
	{
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i][map->j + 1] == 'X')
			game_over();
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i][map->j + 1] != '1'
			&& map->map[map->i][map->j + 1] != 'E')
		{
			move_right(map);
			break ;
		}
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i][map->j + 1] == 'E'
			&& map->c == 0)
		{
			win_game();
			break ;
		}
		map->j++;
	}
}

void	check_left(t_map *map)
{
	while (map->j < (ft_strlen(map->map[0]) - 1))
	{
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i][map->j - 1] == 'X')
			game_over();
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i][map->j - 1] != '1'
			&& map->map[map->i][map->j - 1] != 'E')
		{
			move_left(map);
			break ;
		}
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i][map->j - 1] == 'E'
			&& map->c == 0)
		{
			win_game();
			break ;
		}
		map->j++;
	}
}

void	check_up(t_map *map)
{
	while (map->j < (ft_strlen(map->map[0]) - 1))
	{
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i - 1][map->j] == 'X')
			game_over();
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i - 1][map->j] != '1'
			&& map->map[map->i - 1][map->j] != 'E')
		{
			move_up(map);
			break ;
		}
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i - 1][map->j] == 'E'
			&& map->c == 0)
		{
			win_game();
			break ;
		}
		map->j++;
	}
}

void	check_down(t_map *map)
{
	while (map->j < (ft_strlen(map->map[0]) - 1))
	{
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i + 1][map->j] == 'X')
			game_over();
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i + 1][map->j] != '1'
			&& map->map[map->i + 1][map->j] != 'E')
		{
			move_down(map);
			break ;
		}
		if (map->map[map->i][map->j] == 'P'
			&& map->map[map->i + 1][map->j] == 'E'
			&& map->c == 0)
		{
			win_game();
			break ;
		}
		map->j++;
	}
}
