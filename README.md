# Intro_cpp_Pokemon
##  Attention le fichier introduction_c--pokemon est celui de Matthieu LE non le mieux, il est celui qu'on avait pull pour tester.

## Etat du jeu au moment du tag Evaluation :

On peut lancer une partie en disant Y à la première question ou N parce que je n'ai pas encore coder ce cas. Ensuite on rencontre un pokemon sauvage directement qu'on doit combattre ou capturer avec le pokemon donné de base : hariyama. Cela cloture la partie du code fait.
Problème : si au moment du choix du pokemon par id on met un autre id que celui de hariyama qui est en possession on peut utiliser n'importe quel pokemon.

## Etat du jeu après le second push :

Le jeu consiste à rencontrer d'abord 6 Pokemons sauvage puis un dresseur. Pour gagner il faut battre le dresseur avec plus de 3 pokemons encore en vie. Sachant que le dresseur envoie un nouveau pokemon à chaque fois que vous ou lui perdais un pokemon. Il s'agit donc de 6 1 contre 1 ou vous pouvez envoyer n'importe lequel des pokemon que vous avait même si il lui reste 2 hp.
Durant la phase de capture le taux de capture des pokemons sauvage est de 50%. Vous n'avez le droit de rencontré que 6 pokemon sauvage avant le combat contre le dresseur. Le taux de louper sur les attaques de 20%. Clairement le but est de capturer le plus de pokemon en prenant le moins de dégats pour arrivé au dresseur avec 6 pokemon en bonne santé.
