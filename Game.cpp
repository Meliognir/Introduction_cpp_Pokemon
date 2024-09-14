#include "Game.hpp"
#include <iostream>
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"

using std::string;

void Game::InitGame() {

    Pokeball pokeball;

    std::vector<int> ids = {1,4,7,11,12,13};
    PokemonParty pokemon_party (ids, &pokeball);

    string choixA;
    while(choixA!="Y" ||choixA!="N") {
        if(choixA!="Y" ||choixA!="N"){
        std::cout << "Voulez-vous lancer le jeu ? [Y/N]"<< std::endl;
        std::cin>>choixA;
        }
        if(choixA=="Y") {
            string choixB;
            std::cout << "Rentrez votre pseudo : "<< std::endl;
            std::cin>>choixB;
            std::cout << "C'est parti, "<< choixB << " !"<<std::endl;
            break;
        }

        if(choixA=="N") {
            std::abort(); //apparemment à éviter parce que trop violent
        }

    }


}


/*

    while(PokAdver.getHitPoint()!=0){
        string choix2;
        std::cout << "Voulez-vous attaquer ou capturer ? [Att/Capt]"<< std::endl;
        std::cin>>choix2;
        if(choix2=="Att") {
            arrayOfPokemon.at(index)->attack(*PokAdver);
        }
        if(choix2=="Capt") {
            if(rand() % 100 >=20){
                std::cout << "Vous avez capturé " << arrayOfPokemon.at(index)->getName() << std::endl;
                pokeball.setOnePokemonInPokeballByName(arrayOfPokemon.at(index)->getName());
            }
            else {
                std::cout << "Vous avez raté " << arrayOfPokemon.at(index)->getName()<< std::endl;

            }
        }
    }
}*/


