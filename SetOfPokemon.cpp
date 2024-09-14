#include "SetOfPokemon.hpp"
#include <iostream>


void SetOfPokemon::displayList() {

    for (Pokemon * pokemon : arrayOfPokemon) {
        pokemon->displayInfo();
    }
}

int SetOfPokemon::findOnePokemonByName(const string &name) const {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if(name==arrayOfPokemon.at(i)->getName()) {
            return i;
        }
    }
    return -1;
}

int SetOfPokemon::findOnePokemonById(int id) const {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if(id==arrayOfPokemon.at(i)->getId()) {
            return i;
        }
    }
    return -1;
}

