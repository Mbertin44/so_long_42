/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momo <momo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:38:47 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/11 11:00:00 by momo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
