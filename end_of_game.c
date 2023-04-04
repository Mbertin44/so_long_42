/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:38:47 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/06 08:42:40 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	win_game(void)
{
	printf("YOU WIN !\n");
	exit (0);
}

int	esc_game(void)
{
	printf("You have clicked on the cross to quit the game! Go to work...\n");
	exit (0);
}

void	game_over(void)
{
	printf("You hit a villain. Open your eyes ?\n");
	exit(0);
}
