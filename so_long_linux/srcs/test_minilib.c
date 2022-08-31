/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minilib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:29:49 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/29 13:06:28 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "../include/so_long.h"



int	main(int argc, char const *argv[])
{
	t_mlx	*game;

	game = malloc(sizeof(t_mlx));
	// game->img_height = 0;
	// game->img_width = 0;
	game->mlx = mlx_init();
	// game->img = mlx_xpm_file_to_image(game->mlx,
	// 		"Image/chest_close.xpm", &game->img_width,
	// 		&game->img_height);
	game->win = mlx_new_window(game->mlx, 500, 500, "test");
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->img, 10, 10);
	mlx_hook(game->win, 2, 0, &close_game, game);
	mlx_hook(game->win, 17, 0, &close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

/*

	- Pour compiler : cc -I /usr/local/include test_minilib.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
	- Check des leaks : leaks --atExit -- nom_programme map.ber
	--------------------------------------------------------------------------------------------------------------------------------------------

													--------  MLX -----------

	Dans l'ordre :

	- game->mlx = mlx_init(); Identifiant de connexion au serveur graphique
	- game->img = mlx_xpm_file_to_image(game->mlx, path,
			&game->img_width, &game->img_height); Conversion de mon xpm en image et stocke dans game->img
	- game->win = mlx_new_window(game->mlx, 500, 500, "test"); Création de la fenêtre graphique
	- mlx_key_hook(game->win, deal_key, (void*)0);  Il m'est possible de donner une fonction à la place de deal_key.
		Le parametre void va être donné en parametre à ma fonction deal_key pour que je puisse m'en servir dans celle-ci.
	- mlx_loop(game->mlx); //Pour dessiner ce qui est demandé et récupérer les évenements des utilisateurs


		Si je veux deplacer un personnage, dans l'ordre :

		- gestion de la touche "appuyé" et savoir c'est quel touche (WASD)
		- fonction qui verifie si le comportement est valide (UN mur à droite ? une ressource ... )
		- Executer le mouvement (donc modifier transformer mon 0 par P et le P par un 0 par xemple)
			Par exemple si P qui ce trouve a [x][y] veut aller à droite, alors [x][y] = 0 et [x][y +1] = P
		- Et enfin regénérer ma map (Avec une fonction que j'aurais écrite)
*/
