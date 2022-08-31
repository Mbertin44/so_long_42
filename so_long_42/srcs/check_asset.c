/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:24:53 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/31 15:37:46 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_unknow_set(t_map *map)
{
	int			i;
	size_t		j;
	const char	*set;

	i = 0;
	j = 0;
	set = "01CEPX";
	while (i < map->x - 1)
	{
		while (j < ft_strlen(map->map[0]) - 1)
		{
			if (ft_strchr(set, map->map[i][j]) == NULL)
			{
				printf("Error\nA item '%c' is unknown in line %d, column %zd\n",
					map->map[i][j], ((i) + 1), ((j) + 1));
				exit (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	count_set(t_map *map)
{
	int			x;
	size_t		y;

	x = 0;
	y = 0;
	map->e = 0;
	map->p = 0;
	map->c = 0;
	while (x++ < map->x - 1)
	{
		while (y < (ft_strlen(map->map[0]) - 1))
		{
			if (map->map[x][y] == 'C')
				map->c++;
			if (map->map[x][y] == 'P')
				map->p++;
			if (map->map[x][y] == 'E')
				map->e++;
			y++;
		}
		y = 0;
	}
}

void	check_error_number_set(t_map *map)
{
	if (map->c < 1)
	{
		printf("Error\nThe number of collectibles is less than 1\n");
		exit (1);
	}
	if (map->e != 1)
	{
		printf("Error\nThere must be only one exit\n");
		exit (1);
	}
	if (map->p != 1)
	{
		printf("Error\nThere should only be ONE starting point");
		exit (1);
	}
}
