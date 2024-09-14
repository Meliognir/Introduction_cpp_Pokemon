#include "Combat.hpp"
#include "PokemonParty.hpp"
#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include <vector>
#include <string>
#include <iostream>


Pokemon *Combat::lanceCombatSauvage(PokemonParty &pokemon_party, Pokeball &pokeball){
    //instances

    Pokedex *pokedexInstance=Pokedex::getInstance();

    srand(time(NULL));
    int id=(rand()%720)+1;
    Pokemon * PokAdver= pokedexInstance->getOnePokemonById(id);
    //si problème d'id avec le pokemon adverse
    if (!PokAdver) {
        std::cerr << "Erreur: Pokémon avec ID " << id << " non trouvé dans le Pokédex." << std::endl;
        return PokAdver;
    }
    std::cout << "********************************************" <<std::endl;
    std::cout << "Vous avez rencontré un "<< PokAdver->getName()<< " sauvage." <<std::endl;
    std::cout << "********************************************" <<std::endl;

    int choix1; //id du pokemon
    std::cout << "Quel pokemon voulez-vous envoyer au combat (taper l'ID du pokemon) ?"<< std::endl;
    std::cout << "Vos Pokemon sont : " << std::endl;
    pokemon_party.displayList();
    std::cin>>choix1;
    Pokemon * myPokemon=pokemon_party.getOnePokemonById(choix1);

    std::cout << "Vous avez envoyé "<< myPokemon->getName() << " au combat." <<std::endl;
    //std::vector<int> ids = {myPokemon->getId(),111,111,111,111,111};
    //PokemonParty pokemon_party(ids,&pokeball);
    while(PokAdver->getHP()>=0 || myPokemon->getHP()>=0){
        string choix2;
        std::cout << "Voulez-vous attaquer ou capturer ? [Att/Capt]"<< std::endl;
        std::cin>>choix2;
        if(choix2=="Att") {
            myPokemon->attack(*PokAdver);
            PokAdver->attack(*myPokemon);
            if (PokAdver->getHP()>=0 && myPokemon->getHP()<=0) {
                std::cout << "You LOSE !" << std::endl;
                pokeball.destroyOnePokemonById(myPokemon->getId());
                break;
            }
            if (PokAdver->getHP()<=0 && myPokemon->getHP()>=0) {
                std::cout << "You WIN !" << std::endl;
                return PokAdver;
            }
        }
        if(choix2=="Capt") {
            if(rand() % 100 >=50){
                std::cout << "Vous avez capturé " << PokAdver->getName() << std::endl;
                pokeball.setOnePokemonInPokeball(PokAdver->getId());
                return PokAdver;

            }
            else {
                std::cout << "Vous avez raté " << PokAdver->getName()<< std::endl;
                std::cout << "Le pokemon adverse en profite pour vous attaquer : " << std::endl;
                PokAdver->attack(*myPokemon);
            }
        }
    }
}

void Combat::lanceCombatDresseur(PokemonParty &pokemon_party, Pokeball &pokeball) {
    int indexLost=1;
    Pokedex *pokedexInstance=Pokedex::getInstance();
    for (int i =0;i<6;i++) {
        srand(time(NULL));
        int id=(rand()%720)+1;
        Pokemon * PokAdver= pokedexInstance->getOnePokemonById(id);
        //si problème d'id avec le pokemon adverse
        if (!PokAdver) {
            std::cerr << "Erreur: Pokémon avec ID " << id << " non trouvé dans le Pokédex." << std::endl;
        }
        std::cout << "********************************************" <<std::endl;
        std::cout << "Le dresseur adverse envoie un "<< PokAdver->getName() <<std::endl;
        std::cout << "********************************************" <<std::endl;

        int choix1; //id du pokemon
        std::cout << "Quel pokemon voulez-vous envoyer au combat (taper l'ID du pokemon) ?"<< std::endl;
        std::cout << "Vos Pokemon sont : " << std::endl;
        pokemon_party.displayList();
        std::cin>>choix1;
        Pokemon * myPokemon=pokemon_party.getOnePokemonById(choix1);

        std::cout << "Vous avez envoyé "<< myPokemon->getName() << " au combat." <<std::endl;
        while(PokAdver->getHP()>=0 || myPokemon->getHP()>=0){
            myPokemon->attack(*PokAdver);
            PokAdver->attack(*myPokemon);
            if (PokAdver->getHP()>=0 && myPokemon->getHP()<=0) {
                std::cout << "You lost a pokemon !" << std::endl;
                indexLost++;
                pokeball.destroyOnePokemonById(myPokemon->getId());
                break;
            }
            if (PokAdver->getHP()<=0 && myPokemon->getHP()>=0) {
                pokeball.setOnePokemonInPokeball(myPokemon->getId());
                std::cout << "You killed a pokemon !" << std::endl;
                break;
            }
        }
    }

    std::cout<<"Fin du combat !"<<std::endl;
    if(indexLost>=4) {
        std::cout<<"Vous avez perdu, retentez une autre fois !"<< std::endl;
    }else {
        std::cout<<"Vous avez gagné !"<< std::endl;
    }
}

