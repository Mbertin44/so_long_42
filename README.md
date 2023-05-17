<p align="center">
  <img src="https://github.com/byaliego/42-project-badges/blob/main/badges/so_long-bonus.png?raw=true">
</p>

# So_long

Ce projet a été réalisé dans le cadre de la formation à l'école 42. L'objectif était de créer un jeu 2D en utilisant la bibliothèque graphique Minilibx et d'apprendre à gérer les événements et les mouvements d'objets à l'écran.

## Objectifs

Les objectifs de ce projet étaient les suivants :

- Créer un jeu en utilisant la bibliothèque graphique Minilibx.
- Afficher des images à l'écran et gérer leur mouvement.
- Gérer les événements de clavier pour interagir avec le jeu.
- Implémenter des fonctionnalités de base telles que la gestion des collisions et la fin du jeu.

## Prérequis

Pour réaliser ce projet, j'ai utilisé les éléments suivants :

- La bibliothèque graphique [Minilibx](https://github.com/42Paris/minilibx-linux). 
- Les connaissances de base de la programmation en C et de la manipulation d'images.

## Installation

Pour installer ce projet, il suffit de cloner le dépôt depuis GitHub et de compiler le programme avec `make` dans le dossier.

## Utilisation

Pour utiliser ce projet, exécutez le programme en passant le chemin d'un fichier de carte en tant qu'argument.

`./so_long maps/map.ber`

Le jeu se lancera et vous pourrez interagir avec lui en utilisant les touches W, A, S, D pour déplacer le personnage. L'objectif est de récupérer tous les objets sur la carte et de sortir par la porte de sortie. Vous pouvez aussi quitter la jeu en utilisant la touche échap.

Vous pouvez aussi fournir votre propre carte, temps que celle-ci est composé des éléments suivant :
- Un caractère pour le joueur `P`.
- Un caractère pour la sortie `E`.
- Un caractère pour les ennemis `X`.
- La carte est entouré de mur avec le caractère `1`.

## Bonus

Dans le cadre de ce projet, j'ai également ajouté la fonctionnalité bonus suivantes :

- Nouvelle fonctionnalité du jeu: J'ai ajouté des ennemis qui ce déplace en même temps que le joueur. Si un ennemi touche le joueur, la partie s'arrête.

## Conclusion

Ce projet m'a permis d'apprendre à utiliser la bibliothèque graphique Minilibx et à gérer les événements et les mouvements d'objets à l'écran. J'ai également appris à implémenter des fonctionnalités de base pour un jeu, telles que la gestion des collisions et la fin du jeu.

J'espère que ce projet pourra être utile à d'autres personnes qui souhaitent apprendre à créer des jeux en utilisant la bibliothèque graphique Minilibx.

## Remerciement
Merci à [byaliego](https://github.com/byaliego) pour le badge de projet.

