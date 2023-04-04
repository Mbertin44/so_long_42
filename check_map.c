/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:52:14 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/06 08:42:30 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	size_map_vertical(t_map *map)
{
	char	*temp;

	map->x = 0;
	temp = get_next_line(map->fd);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(map->fd);
		map->x++;
	}
	free(temp);
	if (map->x <= 2)
	{
		printf("Error\nThe map is to small\n");
		exit (1);
	}
}

void	print_map(t_map *map)
{
	map->map = malloc(sizeof(char **) * map->x + 1);
	if (!map->map)
		exit (1);
	map->x = 0;
	map->map[map->x] = get_next_line(map->fd);
	while (1)
	{
		map->x++;
		map->map[map->x] = get_next_line(map->fd);
		if (map->map[map->x] == NULL)
			break ;
	}
	printf("\n");
}

void	check_rectangle(t_map *map)
{
	int		i;
	size_t	first_line;

	i = 1;
	first_line = ft_strlen(map->map[0]);
	while (map->map[i] != NULL)
	{
		if (first_line != ft_strlen(map->map[i]) && i != (map->x - 1))
		{
			printf("Error\nMap is not rectangular\n");
			exit (0);
		}
		if (i == (map->x - 1))
		{
			if ((first_line - 1) != ft_strlen(map->map[i]))
			{
				printf("Error\nMap is not rectangular\n");
				exit (0);
			}
		}
		i++;
	}
}

void	check_wall_horizontal(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(map->map[0]) - 1))
	{
		if (map->map[0][i] != '1')
		{
			printf("Error\nA 1 is missing in the top wall\n");
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < ft_strlen(map->map[map->x - 1]))
	{
		if (map->map[map->x - 1][i] != '1')
		{
			printf("Error\nA 1 is missing in the bottom wall\n");
			exit (0);
		}
		i++;
	}
}

void	check_wall_vertical(t_map *map)
{
	int	i;
	int	first_lane;

	i = 0;
	first_lane = ft_strlen(map->map[0]);
	while (i < map->x - 1)
	{
		if (map->map[i][0] != '1')
		{
			printf("Error\nA 1 is missing in the left wall\n");
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < map->x - 1)
	{
		if (map->map[i][first_lane - 2] != '1')
		{
			printf("Error\nA 1 is missing in the right wall\n");
			exit (0);
		}
		i++;
	}
}
