#include <iostream>
#include "Pokemon.hpp"
#include <vector>
#include "Pokedex.hpp"
#include"Pokeball.hpp"
#include "PokemonParty.hpp"
using std::vector;
#include "Game.hpp"




int main() {
    Pokedex *pokedexInstance=Pokedex::getInstance();
    Pokeball pokeball;
    std::vector<int> ids = {1,122,3,452,700,84};
    PokemonParty pokemon_party(ids,&pokeball);
    auto game = new Game();
    game->InitGame();
    game->lanceCombatSauvage(pokemon_party);

}

    /*std::cout << "******* Pokemon test *******" << std::endl;

    /*Pokemon mew("Mew",5,100,30,70,3);
    Pokemon mew2("Mew2",10,100,100,50,3);

    mew.displayInfo();
    mew2.displayInfo();

    mew.attack(mew2);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);

    std::cout << "Nombre de pokemon en memoire : "<< Pokemon::getNumberOfPokemon() << std::endl;

    Pokedex *pokedexInstance=Pokedex::getInstance();
    pokedexInstance;

    Pokemon * test=Pokedex::getInstance()->getOnePokemonById(3);
    Pokemon * test2=Pokedex::getInstance()->getOnePokemonByName("Charizard");

    Pokeball pokeball;
    srand(time(NULL));
    int id= (rand() % 720) +1;
    pokeball.setOnePokemonInPokeball(122);
    pokeball.setOnePokemonInPokeball(id);
    pokeball.setOnePokemonInPokeball(3);
    pokeball.setOnePokemonInPokeball(32);
    pokeball.setOnePokemonInPokeball(452);
    pokeball.setOnePokemonInPokeball(84);
    pokeball.setOnePokemonInPokeball(95);
    pokeball.setOnePokemonInPokeball(700);
    //std::cout << "Pokemon dans la pokeball : "<< pokeballTest->getName() << std::endl;

    pokeball.displayList();


    std::cout << "Nombre de pokemon en memoire : "<< Pokemon::getNumberOfPokemon() << std::endl;


    std::vector<int> ids = {id,122,3,452,700,84};
    PokemonParty pokemon_party(ids,&pokeball);
    pokemon_party.displayList();
    pokeball.displayList();


    return 0;
}*/

