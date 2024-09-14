#include "PokemonParty.hpp"
#include <iostream>
#include "Pokeball.hpp"
#include "Pokedex.hpp"

PokemonParty::PokemonParty(const std::vector<int>& combatPokemon,Pokeball * pokeball) : linkedPokeball (pokeball) {
    if(combatPokemon.size()>6) {
        std::cout<<"Vous avez trop de Pokemon dans votre équipe."<< std::endl;
        std::__throw_bad_exception();
    }
    for(const int id : combatPokemon) {
        Pokemon * pokemon = linkedPokeball->getOnePokemonById(id);
        if (pokemon !=nullptr) {
            setOnePokemonInPokemonParty(pokemon);
        }
    }
}

void PokemonParty::setOnePokemonInPokeball(int id){

    Pokemon* test = Pokedex::getInstance()->getOnePokemonById(id);
    arrayOfPokemon.push_back(test);

}

Pokemon *PokemonParty::getOnePokemonByIndex(int i) {
    Pokemon * toReturn = arrayOfPokemon.at(i);
    this->arrayOfPokemon.erase(arrayOfPokemon.begin()+i);
    return toReturn;
}



Pokemon * PokemonParty::getOnePokemonById(int id){
    int indexInList=this->findOnePokemonById(id);
    if(indexInList!=-1) {
        Pokemon * pout=this->arrayOfPokemon.at(indexInList);
        return pout;
    }

    return nullptr;
}

Pokemon * PokemonParty::getOnePokemonByName(const string name){
    int indexInList=this->findOnePokemonByName(name);
    if(indexInList!=-1) {
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}


void PokemonParty::setOnePokemonInPokemonParty(Pokemon* pokemon) {
    arrayOfPokemon.push_back(pokemon);
}

