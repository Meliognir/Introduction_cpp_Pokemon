#include "Pokeball.hpp"
#include <iostream>
#include "Pokedex.hpp"
using std::string;
#include <cstdlib>

Pokeball::Pokeball() {
    int random = rand()%720;
    Pokemon * freePokemon = Pokedex::getInstance()->getOnePokemonById(random);
    this->arrayOfPokemon.push_back(freePokemon);
}

Pokemon * Pokeball::getOnePokemonByName(string name){
    int indexInList=findOnePokemonByName(name);
    if(indexInList!=-1) {
        Pokemon * pout=this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        return pout;
    }
    return nullptr;
}

Pokemon * Pokeball::getOnePokemonById(int id){
    int indexInList=this->findOnePokemonById(id);
    if(indexInList!=-1) {
        Pokemon * pout=this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        return pout;
    }

    return nullptr;
}

void Pokeball::setOnePokemonInPokeball(int id){

    Pokemon* test = Pokedex::getInstance()->getOnePokemonById(id);
    arrayOfPokemon.push_back(test);

}

void Pokeball::setOnePokemonInPokeballByName(string name){

    Pokemon* test = Pokedex::getInstance()->getOnePokemonByName(name);
    arrayOfPokemon.push_back(test);

}


