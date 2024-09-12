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
    std::cout << "Voulez-vous lancer le jeu ? [Y/N]"<< std::endl;
    std::cin>>choixA;
    if(choixA=="Y") {
        string choixB;
        std::cout << "Rentrez votre pseudo : "<< std::endl;
        std::cin>>choixB;
        std::cout << "C'est parti, "<< choixB << " !"<<std::endl;
    }
        /*std::cout << "Certains pokemons vous ont été donné vous pouvez allez vous battre,"
                     "êtes vous prêt ? [Y/N]"<< std::endl;
        std::cin>>choixB;
        if(choixB=="Y") {
            lanceCombatSauvage(pokemon_party);

        }else {
            std::cout << " Si vous n'êtes pas prêt quitter le jeu :), le combat va se lancer maintenant :" <<std::endl;
            lanceCombatSauvage(pokemon_party);
        }
    }*/
    if(choixA=="N") {
    }
}

void Game::lanceCombatSauvage(PokemonParty &pokemon_party) {
    //instances
    int index=0;
    Pokedex *pokedexInstance=Pokedex::getInstance();
    Pokeball pokeball;

    srand(time(NULL));
    int id=(rand()%720)+1;
    Pokemon * PokAdver= pokedexInstance->getOnePokemonById(id);
    std::cout << "Vous avez rencontré un "<< PokAdver->getName()<< " sauvage." <<std::endl;

    int choix1;
    std::cout << "Quel pokemon voulez-vous envoyer au combat (taper l'ID du pokemon) ?"<< std::endl;
    std::cout << "Vos Pokemon sont : " << std::endl;
    pokeball.displayList();

    std::cin>>choix1;
    std::cout << "Vous avez envoyé"<< choix1 << " au combat" <<std::endl;
    Pokemon * myPokemon=Pokedex::getInstance()->getOnePokemonById(choix1);
    while(PokAdver->getHP()>=0 || myPokemon->getHP()>=0){
        string choix2;
        std::cout << "Voulez-vous attaquer ou capturer ? [Att/Capt]"<< std::endl;
        std::cin>>choix2;
        if(choix2=="Att") {

            myPokemon->attack(*PokAdver);
            PokAdver->attack(*myPokemon);
            if (PokAdver->getHP()>=0 && myPokemon->getHP()<=0) {
                std::cout << "You LOSE !" << std::endl;
                break;
            }
            if (PokAdver->getHP()<=0 && myPokemon->getHP()>=0) {
                std::cout << "You WIN !" << std::endl;
                break;
            }
        }
        if(choix2=="Capt") {
            if(rand() % 100 >=20){
                std::cout << "Vous avez capturé " << PokAdver->getName() << std::endl;
                pokeball.setOnePokemonInPokeballByName(PokAdver->getName());
                break;
            }
            else {
                std::cout << "Vous avez raté " << PokAdver->getName()<< std::endl;

            }
        }
    }


    //pokemon_party.arrayOfPokemon().push_back(choix1);
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


