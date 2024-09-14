#include <iostream>
#include "Pokemon.hpp"
#include <vector>

#include "Pokedex.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
using std::vector;
#include "Game.hpp"
#include "Combat.hpp"



int main() {
    Pokedex *pokedexInstance=Pokedex::getInstance();

    auto game = new Game();
    game->InitGame();

    //boucle de 6 combat sauvage
    Pokeball pokeball;
    pokeball.setOnePokemonInPokeball(3);
    std::vector<int> ids = {3};
    auto combat=new Combat();
    for(int i=0; i<5;i++) {
        PokemonParty pokemon_party(ids,&pokeball);
        std::cout << "Zone de combat sans Dresseur, vous allez rencontrez des Pokemon sauvage, êtes-vous prêt à lancer un combat sauvage [Y/N]?" <<std::endl;
        string choixA;
        while(choixA!="Y" ||choixA!="N") {
            if(choixA!="Y" ||choixA!="N"){
                std::cout << "Veuillez taper Y ou N : "<< std::endl;
                std::cin>>choixA;
            }
            if(choixA=="Y") {

                Pokemon * newPokemon =  combat->lanceCombatSauvage(pokemon_party,pokeball);
                    ids.push_back(newPokemon->getId());
                    break;

            }

            if(choixA=="N") {
                std::cout << "Voulez vous continuer lancer un combat cette fois ?"<< std::endl;
                std::cin>>choixA;
            }

        }
        std::cout << "Vous avez maintenant les pokemons : " << std::endl;
        pokeball.displayList();

        std::cout << "Il vous reste " << 4-i << " combat à faire avant le dresseur."<< std::endl;


    }

    PokemonParty pokemon_party(ids,&pokeball);

    string choixC;

    std::cout<<" Vous avez fait tous vos combat sauvage votre équipe est complete.Il est venu le moment du grand final, êtes-vous prêt ? [Y/N] "
               << std::endl;
    std::cin>>choixC;
    while(choixC!="Y" || choixC!="N") {
        if(choixC!="Y" ||choixC!="N"){
            std::cout << "Veuillez taper Y ou N : "<< std::endl;
            std::cin>>choixC;
        }
        if(choixC=="Y") {
            std::cout<<" *********************************"<< std::endl;
            std::cout<<" Combat Final !"<< std::endl;
            combat->lanceCombatDresseur(pokemon_party,pokeball);
        }

        if(choixC=="N") {
            std::cout << "VOUS N'AVEZ PLUS LE CHOIX BATTEZ VOUS !!"<< std::endl;
            combat->lanceCombatDresseur(pokemon_party,pokeball);

        }
    }
    std::cout<<"Bravo, vous avez fini le jeu !"<<std::endl;

}
