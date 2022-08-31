/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:41:10 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/31 10:52:10 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		check_right(map);
	}
	if (key == 0)
	{
		check_left(map);
	}
	if (key == 13)
	{
		check_up(map);
	}
	if (key == 1)
	{
		check_down(map);
	}
	return (0);
}

void	check_right(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
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
			if (map->map[map->i][map->j] == 'P'
				&& map->map[map->i][map->j + 1] == 'X')
			{
				printf("You hit a villain. Open your eyes ?\n");
				exit(0);
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	check_left(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
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
			if (map->map[map->i][map->j] == 'P'
				&& map->map[map->i][map->j - 1] == 'X')
			{
				printf("You hit a villain. Open your eyes ?\n");
				exit(0);
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	check_up(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
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
			if (map->map[map->i][map->j] == 'P'
				&& map->map[map->i - 1][map->j] == 'X')
			{
				printf("You hit a villain. Open your eyes ?\n");
				exit(0);
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}

void	check_down(t_map *map)
{
	map->i = 0;
	while (map->i < map->x - 1)
	{
		while (map->j < (ft_strlen(map->map[0]) - 1))
		{
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
			if (map->map[map->i][map->j] == 'P'
				&& map->map[map->i + 1][map->j] == 'X')
			{
				printf("You hit a villain. Open your eyes ?\n");
				exit(0);
			}
			map->j++;
		}
		map->i++;
		map->j = 0;
	}
}
